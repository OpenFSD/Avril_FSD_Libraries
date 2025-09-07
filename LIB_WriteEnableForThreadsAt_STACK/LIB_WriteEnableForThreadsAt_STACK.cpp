#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_STACK.h"

Avril_FSD::WriteEnableForThreadsAt_STACK_Framework* ptr_WriteEnableForThreadsAt_STACK_Framework = NULL;

Avril_FSD::Library_WriteEnableForThreadsAt_STACK::Library_WriteEnableForThreadsAt_STACK()
{

}
void* Avril_FSD::Library_WriteEnableForThreadsAt_STACK::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_STACK_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::Library_WriteEnableForThreadsAt_STACK::Write_End(Avril_FSD::WriteEnableForThreadsAt_STACK_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::Library_WriteEnableForThreadsAt_STACK::Write_Start(Avril_FSD::WriteEnableForThreadsAt_STACK_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_STACK_Framework* Avril_FSD::Library_WriteEnableForThreadsAt_STACK::Get_Framework_WriteEnable()
{
    return ptr_WriteEnableForThreadsAt_STACK_Framework;
}
void Avril_FSD::Library_WriteEnableForThreadsAt_STACK::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_STACK_Framework* writeEnable)
{
    ptr_WriteEnableForThreadsAt_STACK_Framework = writeEnable;
}