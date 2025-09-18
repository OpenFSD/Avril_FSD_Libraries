#include "pch.h"

Avril_FSD::Output_Control* ptr_control_Of_Output = NULL;
Avril_FSD::Object* ptr_praiseOutputBuffer_Subset = NULL;
__int8 _out_praiseEventId;
__int8 _out_playerId;


Avril_FSD::Output::Output()
{
    Set_praiseEventId(__int8(255));
    Set_out_playerId(__int8(255));
}

Avril_FSD::Output::~Output()
{
    delete ptr_control_Of_Output;
    delete ptr_praiseOutputBuffer_Subset;
}

void Avril_FSD::Output::Initialise_Control()
{
    Set_control_Of_Output(new class Avril_FSD::Output_Control());
    while (Get_control_Of_Output() == nullptr) { /* wait untill created */ }
}

Avril_FSD::Output_Control* Avril_FSD::Output::Get_control_Of_Output()
{
    return ptr_control_Of_Output;
}
Avril_FSD::Object* Avril_FSD::Output::Get_praiseOutputBuffer_Subset()
{
    return ptr_praiseOutputBuffer_Subset;
}
__int8 Avril_FSD::Output::Get_out_praiseEventId()
{
    return _out_praiseEventId;
}
__int8 Avril_FSD::Output::Get_out_playerId()
{
    return _out_playerId;
}

void Avril_FSD::Output::Set_control_Of_Output(Avril_FSD::Output_Control* output_Control)
{

}
void Avril_FSD::Output::Set_praiseEventId(__int8 value)
{
    _out_praiseEventId = value;
}
void Avril_FSD::Output::Set_out_playerId(__int8 value)
{
    _out_playerId = value;
}

//
void Avril_FSD::Output::Set_OutputBuffer_Subset(Avril_FSD::Praise0_Output* praise0_value)
{
    ptr_praiseOutputBuffer_Subset = reinterpret_cast<Avril_FSD::Object*>(praise0_value);
}
void Avril_FSD::Output::Set_OutputBuffer_Subset(Avril_FSD::Praise1_Output* praise0_value)
{
    ptr_praiseOutputBuffer_Subset = reinterpret_cast<Avril_FSD::Object*>(praise0_value);
}
void Avril_FSD::Output::Set_OutputBuffer_Subset(Avril_FSD::Praise2_Output* praise0_value)
{
    ptr_praiseOutputBuffer_Subset = reinterpret_cast<Avril_FSD::Object*>(praise0_value);
}
