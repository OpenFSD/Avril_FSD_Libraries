#include "pch.h"

class Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Global* ptr_global = NULL;
class Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Control* ptr_WriteEnable_Control = NULL;

Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE()
{
    Set_global(new class Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Global());
    while (Get_global() == NULL) {}
}

Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::~WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE()
{
    delete ptr_global;
    delete ptr_WriteEnable_Control;
}

void Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Initialise_Control()
{
    Set_writeEnable_Control(new class Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Control(ptr_global));
    while (Get_writeEnable_Control() == NULL) {}
}

void Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Write_End(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Get_writeEnable_Control()->Set_flag_WriteState(coreId, obj->Get_writeEnable()->Get_global()->Get_flag_write_IDLE());
    obj->Get_writeEnable()->Get_writeEnable_Control()->Set_new_writeCycle_Try_CoreId_Index(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteActive(coreId) + 1);
    if(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_new_writeCycle_Try_CoreId_Index() == 3)
    {
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_new_writeCycle_Try_CoreId_Index(0);
    }
    obj->Get_writeEnable()->Get_writeEnable_Control()->WriteQue_Update(obj);
    obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_SortQue(obj);
    obj->Get_writeEnable()->Get_writeEnable_Control()->Set_flag_praisingWrite(false);
}
void Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Write_Start(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_Request(obj, coreId);
    obj->Get_writeEnable()->Get_writeEnable_Control()->WriteQue_Update(obj);
    obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_SortQue(obj);
    obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_Activate(obj, coreId);
}
Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Global* Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Get_global()
{
    return ptr_global;
}
Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Control* Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Get_writeEnable_Control()
{
    return ptr_WriteEnable_Control;
}
void Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Set_global(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Global* global)
{
    ptr_global = global;
}
void Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Set_writeEnable_Control(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Control* writeEnableControl)
{
    ptr_WriteEnable_Control = writeEnableControl;
}