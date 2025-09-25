// LIB_WriteEnableForThreadsAt_CLIENTINPUTACTION.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_CLIENTINPUTACTION.h"

Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework* ptr_WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework = NULL;

// This is an example of an exported variable
LIBWRITEENABLEFORTHREADSATCLIENTINPUTACTION_API int nLIBWriteEnableForThreadsAtCLIENTINPUTACTION = 0;

// This is an example of an exported function.
LIBWRITEENABLEFORTHREADSATCLIENTINPUTACTION_API int fnLIBWriteEnableForThreadsAtCLIENTINPUTACTION(void)
{
    return 0;
}
void* Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTINPUTACTION::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTINPUTACTION::Write_End(Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTINPUTACTION::Write_Start(Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework* Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTINPUTACTION::Get_Framework_WriteEnable()
{
    return ptr_WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework;
}
void Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTINPUTACTION::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework* writeEnable)
{
    ptr_WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework = writeEnable;
}

// This is the constructor of a class that has been exported.
Avril_FSD::CLIBWriteEnableForThreadsAtCLIENTINPUTACTION::CLIBWriteEnableForThreadsAtCLIENTINPUTACTION()
{
    return;
}
