// LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE.cpp : Defines the exported functions for the DLL.
//
#include "pch.h"
#include "LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE.h"

Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* ptr_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework = NULL;

// This is an example of an exported variable
LIBWRITEENABLEFORTHREADSATSERVEROUTPUTRECIEVE_API int nLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE=0;

// This is an example of an exported function.
LIBWRITEENABLEFORTHREADSATSERVEROUTPUTRECIEVE_API int fnLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE(void)
{
    return 0;
}
void* Avril_FSD::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE::Write_End(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE::Write_Start(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* Avril_FSD::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE::Get_Framework_WriteEnable()
{
    return ptr_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework;
}
void Avril_FSD::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* writeEnable)
{
    ptr_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework = writeEnable;
}
// This is the constructor of a class that has been exported.
Avril_FSD::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE::CLIBWriteEnableForThreadsAtSERVEROUTPUTRECIEVE()
{
    return;
}
