// LIB_LaunchEnableForConcurrentThreadsAt_CLIENT.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_LaunchEnableForConcurrentThreadsAt_CLIENT.h"

class Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* ptr_LaunchEnableForConcurrentThreadsAt_CLIENT_Framework = NULL;

// This is an example of an exported variable
LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API int nLIBLaunchEnableForConcurrentThreadsAtCLIENT=0;

// This is an example of an exported function.
LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API int fnLIBLaunchEnableForConcurrentThreadsAtCLIENT(void)
{
    return 0;
}
void* Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Initialise_LaunchEnableForConcurrentThreadsAt()
{
    Set_LaunchEnableForConcurrentThreadsAt_CLIENT_Framework(new class Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework());
    while (Get_LaunchEnableForConcurrentThreadsAt_CLIENT_Framework() == NULL) {}
    return (void*)Get_LaunchEnableForConcurrentThreadsAt_CLIENT_Framework();
}

void Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Request_Wait_Launch(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* obj, unsigned char concurrent_CoreId)
{
    obj->Get_LaunchEnableForConcurrentThread()->Thread_Start(obj, concurrent_CoreId);
}

void Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Thread_End(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* obj, unsigned char concurrent_CoreId)
{
    obj->Get_LaunchEnableForConcurrentThread()->Thread_End(obj, concurrent_CoreId);
}

__int8 Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Get_coreId_To_Launch(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_que_CoreToLaunch(0);
}

bool Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Get_Flag_Active(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_flag_core_ACTIVE();
}

bool Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Get_Flag_ConcurrentCoreState(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* obj, unsigned char concurrent_CoreId)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_state_ConcurrentCore(concurrent_CoreId);
}

bool Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Get_Flag_Idle(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_flag_core_IDLE();
}

bool Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Get_State_LaunchBit(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_state_ConcurrentCore(0);
}

void Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Set_state_ConcurrentCore(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* obj, unsigned char concurrent_CoreId, bool value)
{
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_state_ConcurrentCore(concurrent_CoreId, value);
}

Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Get_LaunchEnableForConcurrentThreadsAt_CLIENT_Framework()
{
    return ptr_LaunchEnableForConcurrentThreadsAt_CLIENT_Framework;
}

void Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::Set_LaunchEnableForConcurrentThreadsAt_CLIENT_Framework(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework* framework)
{
    ptr_LaunchEnableForConcurrentThreadsAt_CLIENT_Framework = framework;
}

// This is the constructor of a class that has been exported.
Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtCLIENT::CLIBLaunchEnableForConcurrentThreadsAtCLIENT()
{
    return;
}
