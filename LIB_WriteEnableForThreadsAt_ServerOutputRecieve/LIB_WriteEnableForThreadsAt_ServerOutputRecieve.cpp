#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_ServerOutputRecieve.h"

class Avril_FSD::WriteEnable_ServerOutputRecieve_Framework* ptr_WriteEnable_ServerOutputRecieve_Framework = NULL;

Avril_FSD::WriteEnableForThreadsAt_ServerOutputRecieve_Library::WriteEnableForThreadsAt_ServerOutputRecieve_Library()
{

}
void* Avril_FSD::WriteEnableForThreadsAt_ServerOutputRecieve_Library::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnable_ServerOutputRecieve_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::WriteEnableForThreadsAt_ServerOutputRecieve_Library::Write_End(class WriteEnable_ServerOutputRecieve_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::WriteEnableForThreadsAt_ServerOutputRecieve_Library::Write_Start(class WriteEnable_ServerOutputRecieve_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnable_ServerOutputRecieve_Framework* Avril_FSD::WriteEnableForThreadsAt_ServerOutputRecieve_Library::Get_Framework_WriteEnable()
{
    return ptr_WriteEnable_ServerOutputRecieve_Framework;
}
void Avril_FSD::WriteEnableForThreadsAt_ServerOutputRecieve_Library::Set_writeEnable(Avril_FSD::WriteEnable_ServerOutputRecieve_Framework* writeEnable)
{
    ptr_WriteEnable_ServerOutputRecieve_Framework = writeEnable;
}