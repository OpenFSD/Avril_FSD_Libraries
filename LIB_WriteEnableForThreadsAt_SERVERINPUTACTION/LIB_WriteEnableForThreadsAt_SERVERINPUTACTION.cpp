// LIB_WriteEnableForThreadsAt_SERVERINPUTACTION.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_SERVERINPUTACTION.h"

Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* ptr_WriteEnableForThreadsAt_SERVERINPUTACTION_Framework = NULL;

// This is an example of an exported variable
LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_API int nLIBWriteEnableForThreadsAtSERVERINPUTACTION=0;

// This is an example of an exported function.
LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_API int fnLIBWriteEnableForThreadsAtSERVERINPUTACTION(void)
{
    return 0;
}
void* Avril_FSD::CLIBWriteEnableForThreadsAtSERVERINPUTACTION::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::CLIBWriteEnableForThreadsAtSERVERINPUTACTION::Write_End(Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::CLIBWriteEnableForThreadsAtSERVERINPUTACTION::Write_Start(Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* Avril_FSD::CLIBWriteEnableForThreadsAtSERVERINPUTACTION::Get_Framework_WriteEnable()
{
    return ptr_WriteEnableForThreadsAt_SERVERINPUTACTION_Framework;
}
void Avril_FSD::CLIBWriteEnableForThreadsAtSERVERINPUTACTION::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* writeEnable)
{
    ptr_WriteEnableForThreadsAt_SERVERINPUTACTION_Framework = writeEnable;
}

// This is the constructor of a class that has been exported.
Avril_FSD::CLIBWriteEnableForThreadsAtSERVERINPUTACTION::CLIBWriteEnableForThreadsAtSERVERINPUTACTION()
{
    return;
}
