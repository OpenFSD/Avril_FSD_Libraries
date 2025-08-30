#include "pch.h"

#include <cstddef>
#include <iostream>

class Avril_FSD::Algorithms* ptr_Algorithms = NULL;
class Avril_FSD::Data* ptr_Data = NULL;
class Avril_FSD::Execute* ptr_Execute = NULL;
class Avril_FSD::Global* ptr_Global = NULL;

Avril_FSD::Server::Server()
{
    Set_Global(new class Avril_FSD::Global());
    while (Get_Global() == NULL) { }
    std::cout << "Created => Avril_FSD::Global()" << std::endl;

    Set_Algorithms(new class Avril_FSD::Algorithms());
    while (Get_Algorithms() == NULL) { }
    std::cout << "Created => Avril_FSD::Algorithms()" << std::endl;

    Set_Data(new class Avril_FSD::Data(Get_Global()->Get_NumCores()));
    while (Get_Data() == NULL) { }
    ptr_Data->Initialise_Control();
    std::cout << "Created => Avril_FSD::Data()" << std::endl;

    Set_Execute(new class Avril_FSD::Execute(Get_Global(), Get_Global()->Get_NumCores()));
    while (Get_Execute() == NULL) { }
    Get_Execute()->Initialise_Control(Get_Global()->Get_NumCores(), Get_Global());
    std::cout << "Created => Avril_FSD::Execute" << std::endl;
}

Avril_FSD::Server::~Server()
{
    delete ptr_Global;
    delete ptr_Algorithms;
    delete ptr_Data;
    delete ptr_Execute;
}

Avril_FSD::Algorithms* Avril_FSD::Server::Get_Algorithms()
{
    return ptr_Algorithms;
}

Avril_FSD::Data* Avril_FSD::Server::Get_Data()
{
    return ptr_Data;
}

Avril_FSD::Execute* Avril_FSD::Server::Get_Execute()
{
    return ptr_Execute;
}

Avril_FSD::Global* Avril_FSD::Server::Get_Global()
{
    return ptr_Global;
}

void Avril_FSD::Server::Set_Algorithms(Algorithms* algorithms)
{
    ptr_Algorithms = algorithms;
}
void Avril_FSD::Server::Set_Data(Data* data)
{
    ptr_Data = data;
}
void Avril_FSD::Server::Set_Execute(Execute* execute)
{
    ptr_Execute = execute;
}
void Avril_FSD::Server::Set_Global(Global* global)
{
    ptr_Global = global;
}
