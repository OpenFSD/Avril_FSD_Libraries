#include "pch.h"
#include <cstddef>
#include <thread>
#include "include/LIB_LaunchEnableForConcurrentThreadsAt_SERVER/LaunchEnableForConcurrentThreadsAt_SERVER_Framework.h"
#include "include/LIB_WriteEnableForThreadsAt_SERVERINPUTACTION/WriteEnableForThreadsAt_SERVERINPUTACTION_Framework.h"
#include "include/LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE/WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework.h"

Avril_FSD::Execute_Control* ptr_Execute_Control = NULL;
std::thread* ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* program_ConcurrentQue_Server = NULL;
Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* program_WriteEnableStack_ServerInputAction = NULL;
Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* program_WriteEnableStack_ServerOutputRecieve = NULL;

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
    program_ConcurrentQue_Server = (Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework*)Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Initialise_LaunchEnableForConcurrentThreadsAt();
    while (program_ConcurrentQue_Server == NULL) {}

    program_WriteEnableStack_ServerInputAction = (Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework*)Avril_FSD::Library_WriteEnableForThreadsAt_SERVERINPUTACTION::Initialise_WriteEnable();
    while (program_WriteEnableStack_ServerInputAction == NULL) {}

    program_WriteEnableStack_ServerOutputRecieve = (Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework*)Avril_FSD::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Initialise_WriteEnable();
    while (program_WriteEnableStack_ServerOutputRecieve == NULL) {}
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

Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework* Avril_FSD::Execute::Get_Program_ConcurrentQue_Server()
{
    return program_ConcurrentQue_Server;
}

Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* Avril_FSD::Execute::Get_Program_WriteEnable_ServerInputAction()
{
    return program_WriteEnableStack_ServerInputAction;
}

Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* Avril_FSD::Execute::Get_Program_WriteEnable_ServerOutputRecieve()
{
    return program_WriteEnableStack_ServerOutputRecieve;
}

void Avril_FSD::Execute::Set_Control_Of_Execute(Execute_Control* execute_Control)
{
    ptr_Execute_Control = execute_Control;
}
