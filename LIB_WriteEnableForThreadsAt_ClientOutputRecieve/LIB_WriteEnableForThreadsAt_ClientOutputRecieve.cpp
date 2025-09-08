#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE.h"

Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* ptr_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework = NULL;

Avril_FSD::Library_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE::Library_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE()
{

}
void* Avril_FSD::Library_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::Library_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE::Write_End(Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::Library_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE::Write_Start(Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* Avril_FSD::Library_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE::Get_Framework_WriteEnable()
{
    return ptr_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework;
}
void Avril_FSD::Library_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework* writeEnable)
{
    ptr_WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework = writeEnable;
}