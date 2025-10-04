#include "pch.h"

Avril_FSD::Concurrent_Control* ptr_Concurrent_Control = NULL;
Avril_FSD::Object* ptr_Algorithms_Subset = NULL;

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

void Avril_FSD::Concurrent::Thread_Concurrency(Avril_FSD::Framework_Server* obj, __int8 concurrent_coreId)
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
        if (Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_ConcurrentCoreState(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server(), concurrent_coreId) == Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_Idle(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()))
        {
            Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Set_state_ConcurrentCore(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server(), concurrent_coreId, Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_Active(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()));
            if (obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Get_flag_IsStackLoaded_Server_InputAction() == true)
            {
                Avril_FSD::CLIBWriteEnableForThreadsAtSERVERINPUTACTION::Write_Start(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerInputAction(), concurrent_coreId + 1);
                obj->Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_control_Of_Output()->SelectSet_Output_Subset(obj, obj->Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_out_praiseEventId(), concurrent_coreId);
                obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Get_Concurrent_Control()->SelectSet_Algorithm_Subset(obj, obj->Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(), concurrent_coreId);
                obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Store_Praise_In_Data_To_GameInstance_Data(obj, obj->Get_Server_Assembly()->Get_Data()->Get_Stack_InputPraise());
                obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Pop_Stack_InputPraises(obj, concurrent_coreId);
                Avril_FSD::CLIBWriteEnableForThreadsAtSERVERINPUTACTION::Write_End(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerInputAction(), concurrent_coreId + 1);
                obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Do_Concurrent_Algorithm_For_PraiseEventId(
                    obj,
                    obj->Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->Get_playerId(),
                    obj->Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Get_Algorithm_Subset(),
                    obj->Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->Get_InputBuffer_Subset(),
                    obj->Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_praiseOutputBuffer_Subset()
                );
                Avril_FSD::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE::Write_Start(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerOutputRecieve(), concurrent_coreId + 1);
                obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Push_Stack_Output(obj, concurrent_coreId);
                obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Store_Praise_Out_Data_To_GameInstance_Data(obj, obj->Get_Server_Assembly()->Get_Data()->Get_Stack_OutputPraise());
                Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Set_state_ConcurrentCore(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server(), concurrent_coreId, Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_Idle(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()));
                Avril_FSD::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE::Write_End(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_WriteEnable_ServerOutputRecieve(), concurrent_coreId + 1);
                Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Thread_End(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server(), concurrent_coreId);
                if (obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Get_flag_IsStackLoaded_Server_OutputRecieve() == true)
                {
                    if (Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_ConcurrentCoreState(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server(), Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_coreId_To_Launch(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server())) == Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_Idle(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()))
                    {
                        Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Request_Wait_Launch(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server(), Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_coreId_To_Launch(obj->Get_Server_Assembly()->Get_Execute()->Get_Program_ConcurrentQue_Server()));
                    }
                }
            }
        }
    }
}

void Avril_FSD::Concurrent::Do_Concurrent_Algorithm_For_PraiseEventId(
    Avril_FSD::Framework_Server* obj,
    char playerId,
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

    case 1: 
        ptr_Algorithm_Subset_Praise1 = reinterpret_cast <Avril_FSD::Praise1_Algorithm*> (ptr_Algorithm_Subset);
        ptr_Input_Subset_Praise1 = reinterpret_cast <Avril_FSD::Praise1_Input*> (ptr_Input_Subset);
        ptr_Output_Subset_Praise1 = reinterpret_cast <Avril_FSD::Praise1_Output*> (ptr_Output_Subset);
        ptr_Algorithm_Subset_Praise1->Do_Praise(obj, playerId, ptr_Input_Subset_Praise1, ptr_Output_Subset_Praise1);
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