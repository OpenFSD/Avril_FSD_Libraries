#include "pch.h"
#include <cstddef>
#include <thread>

#include "LIB_Server_Assembly.h"

class Avril_FSD::Execute_Control* ptr_Execute_Control = NULL;
std::thread* ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES

Avril_FSD::Execute::Execute(Global* ptr_Global, __int8 number_Implemented_Cores)
{

}

Avril_FSD::Execute::~Execute()
{
    delete ptr_Execute_Control;
    for (int index = 0; index < 4; index++)
    {
        delete ptr_Thread_WithCoreId[index];
    }//NUMBER OF CORES
}

void Avril_FSD::Execute::Initialise()
{
    Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Algorithms()->Initialise(
        Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Global()->Get_NumCores()
    );
}

void Avril_FSD::Execute::Initialise_Control(
    __int8 number_Implemented_Cores,
    Avril_FSD::Global* ptr_Global
)
{
    Set_Control_Of_Execute(new class Avril_FSD::Execute_Control(number_Implemented_Cores));
    while (Get_Control_Of_Execute() == NULL) { /* wait untill created */ }
}
void Avril_FSD::Execute::Initialise_Libraries()
{
    class Avril_FSD::Framework_Server* framework = Avril_FSD::LIB_ServerLibrary::Initialise_Server_Assembly();
    class Avril_FSD::Framework_Server* framework = Avril_FSD::LIB_ServerLibrary::Initialise_Server_Assembly();
}
void Avril_FSD::Execute::Initialise_Threads()
{
    for (__int8 coreId = 0; coreId < Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Global()->Get_NumCores(); coreId++)
    {
        ptr_Thread_WithCoreId[coreId] = new std::thread(
            Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(coreId)->Thread_Concurrency,
            coreId,
            Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Global()->Get_NumCores()
        );
    }
}

Avril_FSD::Execute_Control* Avril_FSD::Execute::Get_Control_Of_Execute()
{
    return ptr_Execute_Control;
}

void Avril_FSD::Execute::Set_Control_Of_Execute(Execute_Control* execute_Control)
{
    ptr_Execute_Control = execute_Control;
}
