#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_ClientOutputRecieve.h"

class Avril_FSD::WriteEnable_ClientOutputRecieve_Framework* ptr_WriteEnable_ClientOutputRecieve_Framework = NULL;

Avril_FSD::WriteEnableForThreadsAt_ClientOutputRecieve_Library::WriteEnableForThreadsAt_ClientOutputRecieve_Library()
{

}
void* Avril_FSD::WriteEnableForThreadsAt_ClientOutputRecieve_Library::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnable_ClientOutputRecieve_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::WriteEnableForThreadsAt_ClientOutputRecieve_Library::Write_End(class WriteEnable_ClientOutputRecieve_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::WriteEnableForThreadsAt_ClientOutputRecieve_Library::Write_Start(class WriteEnable_ClientOutputRecieve_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnable_ClientOutputRecieve_Framework* Avril_FSD::WriteEnableForThreadsAt_ClientOutputRecieve_Library::Get_Framework_WriteEnable()
{
    return ptr_WriteEnable_ClientOutputRecieve_Framework;
}
void Avril_FSD::WriteEnableForThreadsAt_ClientOutputRecieve_Library::Set_writeEnable(Avril_FSD::WriteEnable_ClientOutputRecieve_Framework* writeEnable)
{
    ptr_WriteEnable_ClientOutputRecieve_Framework = writeEnable;
}