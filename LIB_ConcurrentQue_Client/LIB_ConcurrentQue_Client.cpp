// LIB_ConcurrentQue_Client.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "LIB_ConcurrentQue_Client.h"

class Avril_FSD::ConcurrentQue_Client_Framework* ptr_ConcurrentQue_Client_Framework = NULL;

Avril_FSD::ConcurrentQue_Client::ConcurrentQue_Client()
{

}

// This is an example of an exported function.
class Avril_FSD::ConcurrentQue_Client_Framework* Avril_FSD::ConcurrentQue_Client::Initialise_ConcurrentQue()
{
    Set_ConcurrentQue_Client_Framework(new class Avril_FSD::ConcurrentQue_Client_Framework());
    while (Get_ConcurrentQue_Client_Framework() == NULL) {}
    return Get_ConcurrentQue_Client_Framework();
}

void Avril_FSD::ConcurrentQue_Client::Request_Wait_Launch(unsigned char concurrent_CoreId)
{
    Get_ConcurrentQue_Client_Framework()->Request_Wait_Launch(concurrent_CoreId);
}

void Avril_FSD::ConcurrentQue_Client::Thread_End(unsigned char concurrent_CoreId)
{
    Get_ConcurrentQue_Client_Framework()->Thread_End(concurrent_CoreId);
}

__int8 Avril_FSD::ConcurrentQue_Client::Get_coreId_To_Launch()
{
    return Get_ConcurrentQue_Client_Framework()->Get_coreId_To_Launch();
}

bool Avril_FSD::ConcurrentQue_Client::Get_Flag_Active()
{
    return Get_ConcurrentQue_Client_Framework()->Get_Flag_Active();
}

bool Avril_FSD::ConcurrentQue_Client::Get_Flag_ConcurrentCoreState(unsigned char concurrent_CoreId)
{
    return Get_ConcurrentQue_Client_Framework()->Get_Flag_ConcurrentCoreState(concurrent_CoreId);
}

bool Avril_FSD::ConcurrentQue_Client::Get_Flag_Idle()
{
    return Get_ConcurrentQue_Client_Framework()->Get_Flag_Idle();
}

bool Avril_FSD::ConcurrentQue_Client::Get_State_LaunchBit()
{
    return Get_ConcurrentQue_Client_Framework()->Get_State_LaunchBit();
}

void Avril_FSD::ConcurrentQue_Client::SetFlag_ConcurrentCoreState(unsigned char concurrent_CoreId, bool value)
{
    Get_ConcurrentQue_Client_Framework()->SetFlag_ConcurrentCoreState(concurrent_CoreId, value);
}

Avril_FSD::ConcurrentQue_Client_Framework* Avril_FSD::ConcurrentQue_Client::Get_ConcurrentQue_Client_Framework()
{
    return ptr_ConcurrentQue_Client_Framework;
}

void Avril_FSD::ConcurrentQue_Client::Set_ConcurrentQue_Client_Framework(class Avril_FSD::ConcurrentQue_Client_Framework* framework)
{
    ptr_ConcurrentQue_Client_Framework = framework;
}
