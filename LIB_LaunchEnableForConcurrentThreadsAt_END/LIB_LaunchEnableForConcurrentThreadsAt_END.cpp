// LIB_LaunchEnableForConcurrentThreadsAt_END.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "LIB_LaunchEnableForConcurrentThreadsAt_END.h"

class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* ptr_LaunchEnableForConcurrentThreadsAt_END_Framework = NULL;

Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Library_LaunchEnableForConcurrentThreadsAt_END()
{

}

// This is an example of an exported function.
void* Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Initialise_LaunchEnableForConcurrentThreadsAt()
{
    Set_LaunchEnableForConcurrentThreadsAt_END_Framework(new class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework());
    while (Get_LaunchEnableForConcurrentThreadsAt_END_Framework() == NULL) {}
    return (void*)Get_LaunchEnableForConcurrentThreadsAt_END_Framework();
}

void Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Request_Wait_Launch(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId)
{
    obj->Get_LaunchEnableForConcurrentThread()->Thread_Start(obj, concurrent_CoreId);
}

void Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Thread_End(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId)
{
    obj->Get_LaunchEnableForConcurrentThread()->Thread_End(obj, concurrent_CoreId);
}

__int8 Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Get_coreId_To_Launch(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_que_CoreToLaunch(0);
}

bool Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Get_Flag_Active(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_flag_core_ACTIVE();
}

bool Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Get_Flag_ConcurrentCoreState(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_state_ConcurrentCore(concurrent_CoreId);
}

bool Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Get_Flag_Idle(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_flag_core_IDLE();
}

bool Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Get_State_LaunchBit(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_state_ConcurrentCore(0);
}

void Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Set_state_ConcurrentCore(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId, bool value)
{
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_state_ConcurrentCore(concurrent_CoreId, value);
}

Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Get_LaunchEnableForConcurrentThreadsAt_END_Framework()
{
    return ptr_LaunchEnableForConcurrentThreadsAt_END_Framework;
}

void Avril_FSD::Library_LaunchEnableForConcurrentThreadsAt_END::Set_LaunchEnableForConcurrentThreadsAt_END_Framework(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* framework)
{
    ptr_LaunchEnableForConcurrentThreadsAt_END_Framework = framework;
}
