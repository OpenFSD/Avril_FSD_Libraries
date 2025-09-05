#include "pch.h"
#include <cstddef>
#include <iostream>

#include "include/LaunchEnableForConcurrentThreadsAt_Server/LIB_LaunchEnableForConcurrentThreadsAt_Server.h"
#include "include/WriteEnableForThreadsAt_ServerInputAction/LIB_WriteEnableForThreadsAt_ServerInputAction.h"
#include "include/WriteEnableForThreadsAt_ServerOutputRecieve/LIB_WriteEnableForThreadsAt_ServerOutputRecieve.h"

class Avril_FSD::Concurrent_Control* ptr_Concurrent_Control = NULL;
class Avril_FSD::Object* ptr_Algorithms_Subset = NULL;

Avril_FSD::Concurrent::Concurrent()
{

}

Avril_FSD::Concurrent::~Concurrent()
{
    delete ptr_Concurrent_Control;
    delete ptr_Algorithms_Subset;
}

void Avril_FSD::Concurrent::Initialise_Control()
{
    Set_Concurrent_Control(new class Avril_FSD::Concurrent_Control());
    while (Get_Concurrent_Control() == NULL) { /* wait untill class constructed */ }
}

Avril_FSD::Concurrent_Control* Avril_FSD::Concurrent::Get_Concurrent_Control()
{
    return ptr_Concurrent_Control;
}

void Avril_FSD::Concurrent::Thread_Concurrency(class Avril_FSD::Framework_Server* obj, __int8 concurrent_coreId)
{
    bool doneOnce = true;
    while (obj->Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_ThreadInitialised(concurrent_coreId) == true)
    {
        if (doneOnce == true)
        {
            obj->Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->SetConditionCodeOfThisThreadedCore(concurrent_coreId + 1);
            doneOnce = false;
        }

    }
    std::cout << "Thread Initialised: ID=" << (concurrent_coreId + 1) << " => Thread_Concurrency()" << std::endl;//TestBench
    while (obj->Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised(obj) == true)
    {

    }
    std::cout << "Thread Starting " << (concurrent_coreId + 1) << " => Thread_Concurrency()" << std::endl;//TestBench
    while (obj->Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised(obj) == false)
    {
        if (obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Get_state_ConcurrentCore(concurrent_coreId) == obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Get_LaunchConcurrency_Global()->Get_flag_core_IDLE())
        {
            obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Set_state_ConcurrentCore(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Get_LaunchConcurrency_Global()->Get_flag_core_ACTIVE(), concurrent_coreId);
        }
        if (obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded() == true)
        {
            obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerInputAction()->Get_writeEnable()->Write_Start(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerInputAction(), concurrent_coreId + 1);
            obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Pop_Stack_InputPraises(obj, concurrent_coreId);
            obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Get_Concurrent_Control()->SelectSet_Algorithm_Subset(obj, obj->Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(), concurrent_coreId);
            obj->Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_Control_Of_Output()->SelectSet_Output_Subset(obj, obj->Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(), concurrent_coreId);
            obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerInputAction()->Get_writeEnable()->Write_End(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerInputAction(), concurrent_coreId + 1);
            obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Do_Concurrent_Algorithm_For_PraiseEventId(
                obj,
                obj->Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Get_Algorithm_Subset(),
                obj->Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->Get_InputBuffer_Subset(),
                obj->Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_OutputBuffer_Subset()
            );
            obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerOutputRecieve()->Get_writeEnable()->Write_Start(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerOutputRecieve(), concurrent_coreId + 1);
            obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Push_Stack_Output(obj, concurrent_coreId);
            obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Thread_End(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server(), concurrent_coreId);
            if (obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded() == true)
            {
                if (obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Get_state_ConcurrentCore(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Get_que_CoreToLaunch(0)) == obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Get_LaunchConcurrency_Global()->Get_flag_core_IDLE())
                {
                    obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Thread_Start(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server(), obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()->Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Get_que_CoreToLaunch(0));
                }
            }
            obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerOutputRecieve()->Get_writeEnable()->Write_End(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerOutputRecieve(), concurrent_coreId + 1);
        }
    }
}

void Avril_FSD::Concurrent::Do_Concurrent_Algorithm_For_PraiseEventId(
    Avril_FSD::Framework_Server* obj,
    __int8 ptr_praiseEventId,
    Object* ptr_Algorithm_Subset,
    Object* ptr_Input_Subset,
    Object* ptr_Output_Subset
)
{
    Avril_FSD::Praise0_Algorithm* ptr_Algorithm_Subset_Praise0 = NULL;
    Avril_FSD::Praise0_Input* ptr_Input_Subset_Praise0 = NULL;
    Avril_FSD::Praise0_Output* ptr_Output_Subset_Praise0 = NULL;
    Avril_FSD::Praise1_Algorithm* ptr_Algorithm_Subset_Praise1 = NULL;
    Avril_FSD::Praise1_Input* ptr_Input_Subset_Praise1 = NULL;
    Avril_FSD::Praise1_Output* ptr_Output_Subset_Praise1 = NULL;
    Avril_FSD::Praise2_Algorithm* ptr_Algorithm_Subset_Praise2 = NULL;
    Avril_FSD::Praise2_Input* ptr_Input_Subset_Praise2 = NULL;
    Avril_FSD::Praise2_Output* ptr_Output_Subset_Praise2 = NULL;
    switch (ptr_praiseEventId)
    {
    case 0:
        ptr_Algorithm_Subset_Praise0 = reinterpret_cast <Avril_FSD::Praise0_Algorithm*> (ptr_Algorithm_Subset);
        ptr_Input_Subset_Praise0 = reinterpret_cast <Avril_FSD::Praise0_Input*> (ptr_Input_Subset);
        ptr_Output_Subset_Praise0 = reinterpret_cast <Avril_FSD::Praise0_Output*> (ptr_Output_Subset);
        ptr_Algorithm_Subset_Praise0->Do_Praise(
            ptr_Input_Subset_Praise0,
            ptr_Output_Subset_Praise0
        );
        break;

    case 1: {
            ptr_Algorithm_Subset_Praise1 = reinterpret_cast <Avril_FSD::Praise1_Algorithm*> (ptr_Algorithm_Subset);
            ptr_Input_Subset_Praise1 = reinterpret_cast <Avril_FSD::Praise1_Input*> (ptr_Input_Subset);
            ptr_Output_Subset_Praise1 = reinterpret_cast <Avril_FSD::Praise1_Output*> (ptr_Output_Subset);
            ptr_Algorithm_Subset_Praise1->Do_Praise(
                ptr_Input_Subset_Praise1,
                ptr_Output_Subset_Praise1
            );
    }
        break;

    case 2:
        ptr_Algorithm_Subset_Praise2 = reinterpret_cast <Avril_FSD::Praise2_Algorithm*> (ptr_Algorithm_Subset);
        ptr_Input_Subset_Praise2 = reinterpret_cast <Avril_FSD::Praise2_Input*> (ptr_Input_Subset);
        ptr_Output_Subset_Praise2 = reinterpret_cast <Avril_FSD::Praise2_Output*> (ptr_Output_Subset);
        ptr_Algorithm_Subset_Praise2->Do_Praise(
            ptr_Input_Subset_Praise2,
            ptr_Output_Subset_Praise2
        );
        break;
    }
}

Avril_FSD::Object* Avril_FSD::Concurrent::Get_Algorithm_Subset()
{
    return ptr_Algorithms_Subset;
}

void Avril_FSD::Concurrent::Set_Algorithm_Subset(Praise0_Algorithm* praise0_algorithm)
{
    ptr_Algorithms_Subset = reinterpret_cast<Avril_FSD::Object*>(praise0_algorithm);
}
void Avril_FSD::Concurrent::Set_Algorithm_Subset(Praise1_Algorithm* praise1_algorithm)
{
    ptr_Algorithms_Subset = reinterpret_cast<Avril_FSD::Object*>(praise1_algorithm);
}
void Avril_FSD::Concurrent::Set_Algorithm_Subset(Praise2_Algorithm* praise2_algorithm)
{
    ptr_Algorithms_Subset = reinterpret_cast<Avril_FSD::Object*>(praise2_algorithm);
}
void Avril_FSD::Concurrent::Set_Concurrent_Control(Concurrent_Control* concurrent_control)
{
    ptr_Concurrent_Control = concurrent_control;
}