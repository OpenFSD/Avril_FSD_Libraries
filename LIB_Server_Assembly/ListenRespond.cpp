#include "pch.h"
#include "ListenRespond.h"
#include <iostream>
#include "include/ConcurrentQue_Server/LIB_ConcurrentQue_Server.h"
#include "include/WriteEnable_Stack_Server_InputAction/LIB_WriteEnable_Stack_Server_InputAction.h"
#include "include/WriteEnable_Stack_Server_OutputRecieve/LIB_WriteEnable_Stack_Server_OutputRecieve.h"

__int8 _thisThreadCoreId;

Avril_FSD::ListenRespond::ListenRespond()
{
	_thisThreadCoreId = 0;
}

Avril_FSD::ListenRespond::~ListenRespond()
{
}
void Avril_FSD::ListenRespond::IO_ListenRespond()
{
    Avril_FSD::Server* serverAssembly = Avril_FSD::Framework_Server::Get_Server_Assembly();
    bool doneOnce = true;
    while (serverAssembly->Get_Execute()->Get_Control_Of_Execute()->GetFlag_ThreadInitialised(Get_thisThreadCoreId()) == true)
    {
        if (doneOnce == true)
        {
            serverAssembly->Get_Execute()->Get_Control_Of_Execute()->SetConditionCodeOfThisThreadedCore(Get_thisThreadCoreId());
            doneOnce = false;
        }
    }
    std::cout << "Thread Initialised => IO_ListenRespond()" << std::endl;//TestBench
    while (Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised() == true)
    {

    }
    std::cout << "Thread Starting => IO_ListenRespond()" << std::endl;//TestBench
    while (serverAssembly->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised() == false)
    {
        ThreadForListen(serverAssembly);
        ThreadForRespond(serverAssembly);
    }
}
void Avril_FSD::ListenRespond::ThreadForListen(Avril_FSD::Server* serverAssembly)
{
    if (serverAssembly->Get_Data()->Get_Data_Control()->GetFlag_isNewInputDataReady())
    {
        Avril_FSD::WriteEnableStackServerInputAction::Write_Start(Get_thisThreadCoreId());
        serverAssembly->Get_Data()->Get_Data_Control()->Push_Stack_InputPraises();
        serverAssembly->Get_Data()->Get_Data_Control()->SetFlag_isNewInputDataReady(false);
        switch (Avril_FSD::ConcurrentQue_Server::Get_State_LaunchBit())
        {
        case true:
            //do nothing and try again next cycle.
            break;

        case false:
            Avril_FSD::ConcurrentQue_Server::Request_Wait_Launch(Get_thisThreadCoreId());
            break;
        }
        Avril_FSD::WriteEnableStackServerInputAction::Write_End(Get_thisThreadCoreId());
    }
}
void Avril_FSD::ListenRespond::ThreadForRespond(Avril_FSD::Server* serverAssembly)
{
    if (serverAssembly->Get_Data()->Get_Data_Control()->GetFlag_isNewOutputDataReady())
    {
        Avril_FSD::WriteEnableStackServerOutputRecieve::Write_Start(Get_thisThreadCoreId());
        while (serverAssembly->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded())
        {
            serverAssembly->Get_Data()->Get_Data_Control()->Pop_Stack_Output();
            serverAssembly->Get_Data()->Flip_Output_DoubleBuffer();
            serverAssembly->Get_Data()->Get_Data_Control()->SetFlag_isNewOutputDataReady(true);
            //SIMULATION: gether output receieve
        }
        Avril_FSD::WriteEnableStackServerOutputRecieve::Write_End(Get_thisThreadCoreId());
    }
}
__int8 Avril_FSD::ListenRespond::Get_thisThreadCoreId()
{
    return _thisThreadCoreId;
}
void Avril_FSD::ListenRespond::Set_listen_CoreId(__int8 thisThreadCoreId)
{
	_thisThreadCoreId = thisThreadCoreId;
}