#include "pch.h"
#include <cstddef>
#include <thread>
#include "include/LaunchEnableForConcurrentThreadsAt_Server/LIB_LaunchEnableForConcurrentThreadsAt_Server.h"
#include "include/WriteEnableForThreadsAt_ServerInputAction/LIB_WriteEnableForThreadsAt_ServerInputAction.h"
#include "include/WriteEnableForThreadsAt_ServerOutputRecieve/LIB_WriteEnableForThreadsAt_ServerOutputRecieve.h"

class Avril_FSD::Execute_Control* ptr_Execute_Control = NULL;
std::thread* ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
class Avril_FSD::ConcurrentQue_Server_Framework* framework_ConcurrentQue_Server = NULL;
class Avril_FSD::WriteEnable_ServerInputAction_Framework* framework_WriteEnableStack_ServerInputAction = NULL;
class Avril_FSD::WriteEnable_ServerOutputRecieve_Framework* framework_WriteEnableStack_ServerOutputRecieve = NULL;

Avril_FSD::Execute::Execute()
{
    Initialise_Libraries();
}

Avril_FSD::Execute::~Execute()
{
    delete ptr_Execute_Control;
    for (int index = 0; index < 4; index++)
    {
        delete ptr_Thread_WithCoreId[index];
    }//NUMBER OF CORES
}

void Avril_FSD::Execute::Initialise(class Avril_FSD::Framework_Server* obj)
{
    obj->Get_Server_Assembly()->Get_Algorithms()->Initialise(obj->Get_Server_Assembly()->Get_Global()->Get_NumCores());
}

void Avril_FSD::Execute::Initialise_Control(__int8 number_Implemented_Cores)
{
    Set_Control_Of_Execute(new class Avril_FSD::Execute_Control(number_Implemented_Cores));
    while (Get_Control_Of_Execute() == NULL) { /* wait untill created */ }
}
void Avril_FSD::Execute::Initialise_Libraries()
{
    framework_ConcurrentQue_Server = new class Avril_FSD::ConcurrentQue_Server_Framework::ConcurrentQue_Server_Framework();
    framework_WriteEnableStack_ServerInputAction = new class Avril_FSD::WriteEnable_ServerInputAction_Framework::WriteEnable_ServerInputAction_Framework();
    framework_WriteEnableStack_ServerOutputRecieve = new class Avril_FSD::WriteEnable_ServerOutputRecieve_Framework::WriteEnable_ServerOutputRecieve_Framework();
}
void Avril_FSD::Execute::Initialise_Threads(class Avril_FSD::Framework_Server* obj)
{
    for (__int8 coreId = 0; coreId < obj->Get_Server_Assembly()->Get_Global()->Get_NumCores(); coreId++)
    {
        ptr_Thread_WithCoreId[coreId] = new std::thread(obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(coreId)->Thread_Concurrency, obj, coreId);
    }
    //todo: add input capture and output send threads
}

Avril_FSD::Execute_Control* Avril_FSD::Execute::Get_Control_Of_Execute()
{
    return ptr_Execute_Control;
}

Avril_FSD::ConcurrentQue_Server_Framework* Avril_FSD::Execute::Get_Program_ConcurrentQue_Server()
{
    return framework_ConcurrentQue_Server;
}

Avril_FSD::WriteEnable_ServerInputAction_Framework* Avril_FSD::Execute::Get_Program_WriteEnable_ServerInputAction()
{
    return framework_WriteEnableStack_ServerInputAction;
}

Avril_FSD::WriteEnable_ServerOutputRecieve_Framework* Avril_FSD::Execute::Get_Program_WriteEnable_ServerOutputRecieve()
{
    return framework_WriteEnableStack_ServerOutputRecieve;
}

void Avril_FSD::Execute::Set_Control_Of_Execute(Execute_Control* execute_Control)
{
    ptr_Execute_Control = execute_Control;
}
