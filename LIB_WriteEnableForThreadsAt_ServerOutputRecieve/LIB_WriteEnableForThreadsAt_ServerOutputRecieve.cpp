#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE.h"

Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* ptr_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework = NULL;

Avril_FSD::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE()
{

}
void* Avril_FSD::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Write_End(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(obj, coreId);
}
void Avril_FSD::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Write_Start(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* Avril_FSD::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Get_Framework_WriteEnable()
{
    return ptr_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework;
}
void Avril_FSD::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* writeEnable)
{
    ptr_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework = writeEnable;
}