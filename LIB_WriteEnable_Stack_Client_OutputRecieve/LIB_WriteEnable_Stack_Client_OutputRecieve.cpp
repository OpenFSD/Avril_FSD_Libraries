// LIB_WriteEnable_Stack_Client_OutputRecieve.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnable_Stack_Client_OutputRecieve.h"

class Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework* ptr_WriteEnable_Stack_Client_OutputRecieve_Framework = NULL;

// This is the constructor of a class that has been exported.
Avril_FSD::WriteEnableStackServerOutputRecieve::WriteEnableStackServerOutputRecieve()
{

}
Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework* Avril_FSD::WriteEnableStackServerOutputRecieve::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return Get_Framework_WriteEnable();
}
void Avril_FSD::WriteEnableStackServerOutputRecieve::Write_End(unsigned char coreId)
{
    Get_Framework_WriteEnable()->Write_End(coreId);
}

void Avril_FSD::WriteEnableStackServerOutputRecieve::Write_Start(unsigned char coreId)
{
    Get_Framework_WriteEnable()->Write_Start(coreId);
}

Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework* Avril_FSD::WriteEnableStackServerOutputRecieve::Get_Framework_WriteEnable()
{
    return ptr_WriteEnable_Stack_Client_OutputRecieve_Framework;
}

void Avril_FSD::WriteEnableStackServerOutputRecieve::Set_writeEnable(Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework* writeEnable)
{
    ptr_WriteEnable_Stack_Client_OutputRecieve_Framework = writeEnable;
}
