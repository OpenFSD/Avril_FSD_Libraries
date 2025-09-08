// LIB_LaunchEnableForConcurrentThreadsAt_SERVER.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_LaunchEnableForConcurrentThreadsAt_SERVER.h"

class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* ptr_LaunchEnableForConcurrentThreadsAt_SERVER_Framework = NULL;

// This is an example of an exported variable
LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API int nLIBLaunchEnableForConcurrentThreadsAtSERVER=0;

// This is an example of an exported function.
LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API int fnLIBLaunchEnableForConcurrentThreadsAtSERVER(void)
{
    return 0;
}
void* Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Initialise_LaunchEnableForConcurrentThreadsAt()
{
    Set_LaunchEnableForConcurrentThreadsAt_SERVER_Framework(new class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework());
    while (Get_LaunchEnableForConcurrentThreadsAt_SERVER_Framework() == NULL) {}
    return (void*)Get_LaunchEnableForConcurrentThreadsAt_SERVER_Framework();
}

void Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Request_Wait_Launch(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj, unsigned char concurrent_CoreId)
{
    obj->Get_LaunchEnableForConcurrentThread()->Thread_Start(obj, concurrent_CoreId);
}

void Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Thread_End(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj, unsigned char concurrent_CoreId)
{
    obj->Get_LaunchEnableForConcurrentThread()->Thread_End(obj, concurrent_CoreId);
}

__int8 Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_coreId_To_Launch(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_que_CoreToLaunch(0);
}

bool Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_Active(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_flag_core_ACTIVE();
}

bool Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_ConcurrentCoreState(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj, unsigned char concurrent_CoreId)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_state_ConcurrentCore(concurrent_CoreId);
}

bool Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_Flag_Idle(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_LaunchConcurrency_Global()->Get_flag_core_IDLE();
}

bool Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_State_LaunchBit(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj)
{
    return obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Get_state_ConcurrentCore(0);
}

void Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Set_state_ConcurrentCore(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* obj, unsigned char concurrent_CoreId, bool value)
{
    obj->Get_LaunchEnableForConcurrentThread()->Get_Control_Of_LaunchConcurrency()->Set_state_ConcurrentCore(concurrent_CoreId, value);
}

Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Get_LaunchEnableForConcurrentThreadsAt_SERVER_Framework()
{
    return ptr_LaunchEnableForConcurrentThreadsAt_SERVER_Framework;
}

void Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Set_LaunchEnableForConcurrentThreadsAt_SERVER_Framework(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* framework)
{
    ptr_LaunchEnableForConcurrentThreadsAt_SERVER_Framework = framework;
}

// This is the constructor of a class that has been exported.
Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::CLIBLaunchEnableForConcurrentThreadsAtSERVER()
{
    return;
}
