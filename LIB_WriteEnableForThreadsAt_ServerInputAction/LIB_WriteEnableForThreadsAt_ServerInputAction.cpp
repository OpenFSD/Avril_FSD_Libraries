#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_SERVERINPUTACTION.h"

Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* ptr_WriteEnableForThreadsAt_SERVERINPUTACTION_Framework = NULL;

Avril_FSD::Library_WriteEnableForThreadsAt_SERVERINPUTACTION::Library_WriteEnableForThreadsAt_SERVERINPUTACTION()
{

}
void* Avril_FSD::Library_WriteEnableForThreadsAt_SERVERINPUTACTION::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::Library_WriteEnableForThreadsAt_SERVERINPUTACTION::Write_End(Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::Library_WriteEnableForThreadsAt_SERVERINPUTACTION::Write_Start(Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* Avril_FSD::Library_WriteEnableForThreadsAt_SERVERINPUTACTION::Get_Framework_WriteEnable()
{
    return ptr_WriteEnableForThreadsAt_SERVERINPUTACTION_Framework;
}
void Avril_FSD::Library_WriteEnableForThreadsAt_SERVERINPUTACTION::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework* writeEnable)
{
    ptr_WriteEnableForThreadsAt_SERVERINPUTACTION_Framework = writeEnable;
}