// LIB_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE.cpp : Defines the exported functions for the DLL.
//
#include "pch.h"
#include "LIB_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE.h"

Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* ptr_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework = NULL;

// This is an example of an exported variable
LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_API int nLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE=0;

// This is an example of an exported function.
LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_API int fnLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE(void)
{
    return 0;
}
void* Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE::Write_End(Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE::Write_Start(Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE::Get_Framework_WriteEnable()
{
    return ptr_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework;
}
void Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* writeEnable)
{
    ptr_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework = writeEnable;
}
// This is the constructor of a class that has been exported.
Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE::CLIBWriteEnableForThreadsAtCLIENTOUTPUTRECIEVE()
{
    return;
}
