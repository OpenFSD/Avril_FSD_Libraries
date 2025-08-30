#include "..\LIB_Server_Assembly\include\WriteEnable_Stack_Server_OutputRecieve\LIB_WriteEnable_Stack_Server_OutputRecieve.h"
// LIB_WriteEnable_Stack_Server_InputAction.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnable_Stack_Server_OutputRecieve.h"

class Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework* ptr_WriteEnableStack_ServerOutputRecieve_Framework = NULL;

// This is the constructor of a class that has been exported.
Avril_FSD::WriteEnableStackServerOutputRecieve::WriteEnableStackServerOutputRecieve()
{

}

Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework* Avril_FSD::WriteEnableStackServerOutputRecieve::Initialise_WriteEnableStack()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework());
    while (Get_writeEnable() == NULL) {}
    return Get_writeEnable();
}

void Avril_FSD::WriteEnableStackServerOutputRecieve::Write_End(unsigned char coreId)
{
    Get_writeEnable()->Write_End(coreId);
}

void Avril_FSD::WriteEnableStackServerOutputRecieve::Write_Start(unsigned char coreId)
{
    Get_writeEnable()->Write_Start(coreId);
}

Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework* Avril_FSD::WriteEnableStackServerOutputRecieve::Get_writeEnable()
{
    return ptr_WriteEnableStack_ServerOutputRecieve_Framework;
}

void Avril_FSD::WriteEnableStackServerOutputRecieve::Set_writeEnable(Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework* writeEnable)
{
}