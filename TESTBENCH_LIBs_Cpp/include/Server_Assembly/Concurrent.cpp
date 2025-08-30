#include "pch.h"

#include <cstddef>
#include <iostream>

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

void Avril_FSD::Concurrent::Thread_Concurrency(__int8 concurrent_coreId, __int8 number_Implemented_Cores)
{
    bool doneOnce = true;
    while (Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_ThreadInitialised(concurrent_coreId) == true)
    {
        if (doneOnce == true)
        {
            Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->SetConditionCodeOfThisThreadedCore(concurrent_coreId);
            doneOnce = false;
        }

    }
    std::cout << "Thread Initialised => Thread_Concurrency()" << std::endl;//TestBench
    while (Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised() == true)
    {

    }
    std::cout << "Thread Starting => Thread_Concurrency()" << std::endl;//TestBench
    while (Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised() == false)
    {
        /*
        if (ConcurrentQue::ConcurrentQue_Server_Framework::Get_Flag_ConcurrentCoreState(concurrent_coreId) == ConcurrentQue::ConcurrentQue_Server_Framework::Get_Flag_Idle())
        {
            ConcurrentQue::ConcurrentQue_Server_Framework::SetFlag_ConcurrentCoreState(concurrent_coreId, ConcurrentQue::ConcurrentQue_Server_Framework::Get_Flag_Active());

            if (Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded() == true)
            {
                WaitEnableWrite::WriteEnable_Stack_Server_InputAction_Framework::Write_Start(1 + concurrent_coreId);
                Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Pop_Stack_InputPraises(concurrent_coreId);

                Avril_FSD::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Get_Concurrent_Control()->SelectSet_Algorithm_Subset(
                    Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    concurrent_coreId
                );
                Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_Control_Of_Output()->SelectSet_Output_Subset(
                    Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    concurrent_coreId
                );
                WaitEnableWrite::WriteEnable_Stack_Server_InputAction_Framework::Write_End(1 + concurrent_coreId);

                Avril_FSD::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Do_Concurrent_Algorithm_For_PraiseEventId(
                    Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    Avril_FSD::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Get_Algorithm_Subset(),
                    Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->Get_InputBuffer_Subset(),
                    Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_OutputBuffer_Subset()
                );

                WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve_Framework::Write_Start(1 + concurrent_coreId);
                Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Push_Stack_Output(concurrent_coreId);
                ConcurrentQue::ConcurrentQue_Server_Framework::Thread_End(concurrent_coreId);
                if (Avril_FSD::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded() == true)
                {
                    if (ConcurrentQue::ConcurrentQue_Server_Framework::Get_Flag_ConcurrentCoreState(ConcurrentQue::ConcurrentQue_Server_Framework::Get_coreId_To_Launch())
                        == ConcurrentQue::ConcurrentQue_Server_Framework::Get_Flag_Idle())
                    {
                        ConcurrentQue::ConcurrentQue_Server_Framework::Request_Wait_Launch(ConcurrentQue::ConcurrentQue_Server_Framework::Get_coreId_To_Launch());
                    }
                }
                WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve_Framework::Write_End(1 + concurrent_coreId);
            }
        }*/
    }
}

void Avril_FSD::Concurrent::Do_Concurrent_Algorithm_For_PraiseEventId(
    __int8 ptr_praiseEventId,
    Object* ptr_Algorithm_Subset,
    Object* ptr_Input_Subset,
    Object* ptr_Output_Subset
)
{
    /*
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
    */
}
class Avril_FSD::Object* Avril_FSD::Concurrent::Get_Algorithm_Subset()
{
    return ptr_Algorithms_Subset;
}
void Avril_FSD::Concurrent::Set_Algorithm_Subset(class Praise0_Algorithm* praise0_algorithm)
{
    ptr_Algorithms_Subset = reinterpret_cast<class Object*>(praise0_algorithm);
}
void Avril_FSD::Concurrent::Set_Algorithm_Subset(class Praise1_Algorithm* praise1_algorithm)
{
    ptr_Algorithms_Subset = reinterpret_cast<class Object*>(praise1_algorithm);
}
void Avril_FSD::Concurrent::Set_Algorithm_Subset(class Praise2_Algorithm* praise2_algorithm)
{
    ptr_Algorithms_Subset = reinterpret_cast<class Object*>(praise2_algorithm);
}
void Avril_FSD::Concurrent::Set_Concurrent_Control(Concurrent_Control* concurrent_control)
{
    ptr_Concurrent_Control = concurrent_control;
}