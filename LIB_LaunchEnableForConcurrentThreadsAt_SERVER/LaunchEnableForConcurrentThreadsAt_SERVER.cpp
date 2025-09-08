#include "pch.h"

#include <cstddef>

class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Global* ptr_Global = NULL;
class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Control* ptr_LaunchConcurrency_Control = NULL;

Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::LaunchEnableForConcurrentThreadsAt_SERVER()
{
    Create_LaunchEnableForConcurrentThreadsAt_SERVER_Global();
}

Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::~LaunchEnableForConcurrentThreadsAt_SERVER()
{
    delete ptr_LaunchConcurrency_Control;
}

void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Initialise_Control()
{
    Create_Control_Of_LaunchConcurrency();
}

void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Thread_Start(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj, unsigned char concurrent_CoreId)
{
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->LaunchEnable_Request(obj, concurrent_CoreId);
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->LaunchQue_Update(obj, obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_number_Implemented_Cores());
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->LaunchEnable_SortQue(obj, obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_number_Implemented_Cores());
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->LaunchEnable_Activate(obj);
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->LaunchQue_Update(obj, obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_number_Implemented_Cores());
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->LaunchEnable_SortQue(obj, obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_number_Implemented_Cores());
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_flag_praisingLaunch(false);
}

void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Thread_End(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj, unsigned char concurrent_CoreId)
{
    while (obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_flag_praisingLaunch() == true)
    {

    }
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_flag_praisingLaunch(true);
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_concurrentCycle_Try_CoreId_Index(obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_new_concurrentCycle_Try_CoreId_Index());
    if (obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_concurrentCycle_Try_CoreId_Index() == concurrent_CoreId)
    {
        obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_state_ConcurrentCore(concurrent_CoreId, obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_flag_core_IDLE());
    }
    else
    {
        obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_new_concurrentCycle_Try_CoreId_Index(obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_concurrentCycle_Try_CoreId_Index() + 1);

        if (obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_new_concurrentCycle_Try_CoreId_Index() == 3)//NUMBER OF CONCURNT CORES
        {
            obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_new_concurrentCycle_Try_CoreId_Index(0);
        }
        obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_flag_praisingLaunch(false);
        obj->Get_LaunchEnableForConcurrentThread()->Thread_End(obj, concurrent_CoreId);
    }
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Create_LaunchEnableForConcurrentThreadsAt_SERVER_Global()
{
    Set_LaunchConcurrency_Global(new class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Global());
    while (Get__LaunchConcurrency_Global() == NULL) {}
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Create_Control_Of_LaunchConcurrency()
{
    Set_Control_Of_LaunchConcurrency(new class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Control(Get__LaunchConcurrency_Global(), Get__LaunchConcurrency_Global()->Get_number_Implemented_Cores()));
    while (Get__Control_Of_LaunchConcurrency() == NULL) { /* wait untill created */ }
}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Global* Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Get_LaunchConcurrency_Global()
{
    return ptr_Global;
}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Control* Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Get_Control_Of_LaunchConcurrency()
{
    return ptr_LaunchConcurrency_Control;
}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Global* Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Get__LaunchConcurrency_Global()
{
    return ptr_Global;
}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Control* Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Get__Control_Of_LaunchConcurrency()
{
    return ptr_LaunchConcurrency_Control;
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Set_LaunchConcurrency_Global(LaunchEnableForConcurrentThreadsAt_SERVER_Global* global)
{
    ptr_Global = global;
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER::Set_Control_Of_LaunchConcurrency(LaunchEnableForConcurrentThreadsAt_SERVER_Control* control)
{
    ptr_LaunchConcurrency_Control = control;
}