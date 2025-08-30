#include "pch.h"

#include <cstddef>

namespace Avril_FSD
{
    class Output_Control* ptr_control_Of_Output = NULL;
    __int8 out_PraiseEventId = 255;
    class Object* ptr_praiseOutputBuffer_Subset = NULL;

    Output::Output()
    {
        SetPraiseEventId(__int8(255));
    }

    Output::~Output()
    {
        delete ptr_control_Of_Output;
        delete ptr_praiseOutputBuffer_Subset;
    }

    void Output::Initialise_Control()
    {
        Set_control_Of_Output(new class Avril_FSD::Output_Control());
        while (Get_Control_Of_Output() == nullptr) { /* wait untill created */ }
    }

    class Output_Control* Output::Get_Control_Of_Output()
    {
        return ptr_control_Of_Output;
    }

    class Object* Output::Get_OutputBuffer_Subset()
    {
        return ptr_praiseOutputBuffer_Subset;
    }

    __int8 Output::GetPraiseEventId()
    {
        return out_PraiseEventId;
    }

    void Output::SetPraiseEventId(__int8 value)
    {
        out_PraiseEventId = value;
    }

    void Output::Set_OutputBuffer_Subset(Praise0_Output* praise0_value)
    {
        ptr_praiseOutputBuffer_Subset = reinterpret_cast<class Object*>(praise0_value);
    }
    void Output::Set_OutputBuffer_Subset(Praise1_Output* praise0_value)
    {
        ptr_praiseOutputBuffer_Subset = reinterpret_cast<class Object*>(praise0_value);
    }
    void Output::Set_OutputBuffer_Subset(Praise2_Output* praise0_value)
    {
        ptr_praiseOutputBuffer_Subset = reinterpret_cast<class Object*>(praise0_value);
    }
    void Avril_FSD::Output::Set_control_Of_Output(Output_Control* output_Control)
    {

    }
}
