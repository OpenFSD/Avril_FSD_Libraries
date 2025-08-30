#include "pch.h"

#include <cstddef>

class Avril_FSD::ConcurrentQue_Client_Global* ptr_Global = NULL;
class Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control* ptr_LaunchConcurrency_Control = NULL;

Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::ConcurrentQue_Client_LaunchConcurrency()
{
    Create_ConcurrentQue_Client_Global();
}

Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::~ConcurrentQue_Client_LaunchConcurrency()
{
    delete ptr_LaunchConcurrency_Control;
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Thread_Start(unsigned char concurrent_CoreId)
{
    Get_Control_Of_LaunchConcurrency()->LaunchEnable_Request(concurrent_CoreId, Get_LaunchConcurrency_Global());
    Get_Control_Of_LaunchConcurrency()->LaunchQue_Update(Get_LaunchConcurrency_Global()->Get_NumCores());
    Get_Control_Of_LaunchConcurrency()->LaunchEnable_SortQue(Get_LaunchConcurrency_Global(), Get_LaunchConcurrency_Global()->Get_NumCores());
    Get_Control_Of_LaunchConcurrency()->LaunchEnable_Activate(Get_LaunchConcurrency_Global());
    Get_Control_Of_LaunchConcurrency()->LaunchQue_Update(Get_LaunchConcurrency_Global()->Get_NumCores());
    Get_Control_Of_LaunchConcurrency()->LaunchEnable_SortQue(Get_LaunchConcurrency_Global(), Get_LaunchConcurrency_Global()->Get_NumCores());
    Get_Control_Of_LaunchConcurrency()->SetFlag_PraisingLaunch(false);
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Initialise_Control()
{
    Create_Control_Of_LaunchConcurrency();
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Thread_End(unsigned char concurrent_CoreId)
{
    while (Get_Control_Of_LaunchConcurrency()->GetFlag_PraisingLaunch() == true)
    {

    }
    Get_Control_Of_LaunchConcurrency()->SetFlag_PraisingLaunch(true);
    Get_Control_Of_LaunchConcurrency()->Set_concurrent_CoreId_Index(Get_Control_Of_LaunchConcurrency()->Get_new_concurrent_CoreId_Index());
    if (Get_Control_Of_LaunchConcurrency()->Get_concurrent_CoreId_Index() == concurrent_CoreId)
    {
        Get_Control_Of_LaunchConcurrency()->SetFlag_ConcurrentCoreState(concurrent_CoreId, Get_LaunchConcurrency_Global()->GetConst_Core_IDLE());
    }
    else
    {
        Get_Control_Of_LaunchConcurrency()->Set_new_concurrent_CoreId_Index(Get_Control_Of_LaunchConcurrency()->Get_concurrent_CoreId_Index() + 1);

        if (Get_Control_Of_LaunchConcurrency()->Get_new_concurrent_CoreId_Index() == 3)//NUMBER OF CONCURNT CORES
        {
            Get_Control_Of_LaunchConcurrency()->Set_new_concurrent_CoreId_Index(0);
        }
        Get_Control_Of_LaunchConcurrency()->SetFlag_PraisingLaunch(false);
        Thread_End(concurrent_CoreId);
    }
}
void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Create_ConcurrentQue_Client_Global()
{
    Set_LaunchConcurrency_Global(new class Avril_FSD::ConcurrentQue_Client_Global());
    while (Get_LaunchConcurrency_Global() == NULL) {}
}
void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Create_Control_Of_LaunchConcurrency()
{
    Set_Control_Of_LaunchConcurrency(new class Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control(Get_LaunchConcurrency_Global(), Get_LaunchConcurrency_Global()->Get_NumCores()));
    while (Get_Control_Of_LaunchConcurrency() == NULL) { /* wait untill created */ }
}
Avril_FSD::ConcurrentQue_Client_Global* Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Get_LaunchConcurrency_Global()
{
    return ptr_Global;
}
Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control* Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Get_Control_Of_LaunchConcurrency()
{
    return ptr_LaunchConcurrency_Control;
}
void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Set_LaunchConcurrency_Global(ConcurrentQue_Client_Global* global)
{
    ptr_Global = global;
}
void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency::Set_Control_Of_LaunchConcurrency(ConcurrentQue_Client_LaunchConcurrency_Control* control)
{
    ptr_LaunchConcurrency_Control = control;
}