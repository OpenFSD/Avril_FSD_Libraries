// LIB_ConcurrentQue_Server.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "LIB_ConcurrentQue_Server.h"

class Avril_FSD::ConcurrentQue_Server_Framework* ptr_ConcurrentQue_Server_Framework = NULL;

Avril_FSD::ConcurrentQue_Server::ConcurrentQue_Server()
{

}

// This is an example of an exported function.
class Avril_FSD::ConcurrentQue_Server_Framework* Avril_FSD::ConcurrentQue_Server::Initialise_ConcurrentQue()
{
    Set_ConcurrentQue_Server_Framework(new class Avril_FSD::ConcurrentQue_Server_Framework());
    while (Get_ConcurrentQue_Server_Framework() == NULL) {}
    return Get_ConcurrentQue_Server_Framework();
}

void Avril_FSD::ConcurrentQue_Server::Request_Wait_Launch(unsigned char concurrent_CoreId)
{
    Get_ConcurrentQue_Server_Framework()->Request_Wait_Launch(concurrent_CoreId);
}

void Avril_FSD::ConcurrentQue_Server::Thread_End(unsigned char concurrent_CoreId)
{
    Get_ConcurrentQue_Server_Framework()->Thread_End(concurrent_CoreId);
}

__int8 Avril_FSD::ConcurrentQue_Server::Get_coreId_To_Launch()
{
    return Get_ConcurrentQue_Server_Framework()->Get_coreId_To_Launch();
}

bool Avril_FSD::ConcurrentQue_Server::Get_Flag_Active()
{
    return Get_ConcurrentQue_Server_Framework()->Get_Flag_Active();
}

bool Avril_FSD::ConcurrentQue_Server::Get_Flag_ConcurrentCoreState(unsigned char concurrent_CoreId)
{
    return Get_ConcurrentQue_Server_Framework()->Get_Flag_ConcurrentCoreState(concurrent_CoreId);
}

bool Avril_FSD::ConcurrentQue_Server::Get_Flag_Idle()
{
    return Get_ConcurrentQue_Server_Framework()->Get_Flag_Idle();
}

bool Avril_FSD::ConcurrentQue_Server::Get_State_LaunchBit()
{
    return Get_ConcurrentQue_Server_Framework()->Get_State_LaunchBit();
}

void Avril_FSD::ConcurrentQue_Server::SetFlag_ConcurrentCoreState(unsigned char concurrent_CoreId, bool value)
{
    Get_ConcurrentQue_Server_Framework()->SetFlag_ConcurrentCoreState(concurrent_CoreId, value);
}

Avril_FSD::ConcurrentQue_Server_Framework* Avril_FSD::ConcurrentQue_Server::Get_ConcurrentQue_Server_Framework()
{
    return ptr_ConcurrentQue_Server_Framework;
}

void Avril_FSD::ConcurrentQue_Server::Set_ConcurrentQue_Server_Framework(class Avril_FSD::ConcurrentQue_Server_Framework* framework)
{
    ptr_ConcurrentQue_Server_Framework = framework;
}
