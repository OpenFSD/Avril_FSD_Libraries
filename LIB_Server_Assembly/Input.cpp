#include "pch.h"

Avril_FSD::Input_Control* ptr_input_Control = NULL;
__int8 _in_praiseEventId = 255;
__int8 _in_playerId = 255;
Avril_FSD::Object* ptr_buffer_SubSet_InputPraise = NULL;

Avril_FSD::Input::Input()
{
    Set_in_praiseEventId(__int8(255));
}

Avril_FSD::Input::~Input()
{
    delete ptr_input_Control;
    delete ptr_buffer_SubSet_InputPraise;
}

void Avril_FSD::Input::Initialise_Control()
{
    Set_input_Control(new class Avril_FSD::Input_Control());
    while (Get_Input_Control() == NULL) {}
}

class Avril_FSD::Input_Control* Avril_FSD::Input::Get_Input_Control()
{
    return ptr_input_Control;
}
class Avril_FSD::Object* Avril_FSD::Input::Get_InputBuffer_Subset()
{
    return ptr_buffer_SubSet_InputPraise;
}
__int8 Avril_FSD::Input::GetPraiseEventId()
{
    return _in_praiseEventId;
}
__int8 Avril_FSD::Input::Get_playerId()
{
    return _in_playerId;
}
void Avril_FSD::Input::Set_in_praiseEventId(__int8 value)
{
    _in_praiseEventId = value;
}
void Avril_FSD::Input::Set_in_playerId(__int8 value)
{
    _in_playerId = value;
}
void Avril_FSD::Input::Set_input_Control(Avril_FSD::Input_Control* input_Control)
{
    ptr_input_Control = input_Control;
}

void Avril_FSD::Input::Set_Subset_InputBuffer(Avril_FSD::Praise0_Input* praise0_value)
{
    ptr_buffer_SubSet_InputPraise = reinterpret_cast<Avril_FSD::Object*>(praise0_value);
}

void Avril_FSD::Input::Set_Subset_InputBuffer(Avril_FSD::Praise1_Input* praise1_value)
{
    ptr_buffer_SubSet_InputPraise = reinterpret_cast<Avril_FSD::Object*>(praise1_value);
}

void Avril_FSD::Input::Set_Subset_InputBuffer(Avril_FSD::Praise2_Input* praise2_value)
{
    ptr_buffer_SubSet_InputPraise = reinterpret_cast<Avril_FSD::Object*>(praise2_value);
}