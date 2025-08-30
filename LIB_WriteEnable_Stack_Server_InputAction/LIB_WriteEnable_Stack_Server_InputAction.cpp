// LIB_WriteEnable_Stack_Server_InputAction.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnable_Stack_Server_InputAction.h"

class Avril_FSD::WriteEnableStack_ServerInputAction_Framework* ptr_WriteEnableStack_ServerInputAction_Framework = NULL;

// This is the constructor of a class that has been exported.
Avril_FSD::WriteEnableStackServerInputAction::WriteEnableStackServerInputAction()
{

}

Avril_FSD::WriteEnableStack_ServerInputAction_Framework* Avril_FSD::WriteEnableStackServerInputAction::Initialise_WriteEnableStack()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableStack_ServerInputAction_Framework());
    while (Get_writeEnable() == NULL) {}
    return Get_writeEnable();
}

void Avril_FSD::WriteEnableStackServerInputAction::Write_End(unsigned char coreId)
{
    Get_writeEnable()->Write_End(coreId);
}

void Avril_FSD::WriteEnableStackServerInputAction::Write_Start(unsigned char coreId)
{
    Get_writeEnable()->Write_Start(coreId);
}

Avril_FSD::WriteEnableStack_ServerInputAction_Framework* Avril_FSD::WriteEnableStackServerInputAction::Get_writeEnable()
{
    return ptr_WriteEnableStack_ServerInputAction_Framework;
}

void Avril_FSD::WriteEnableStackServerInputAction::Set_writeEnable(Avril_FSD::WriteEnableStack_ServerInputAction_Framework* writeEnable)
{
    ptr_WriteEnableStack_ServerInputAction_Framework = writeEnable;
}
