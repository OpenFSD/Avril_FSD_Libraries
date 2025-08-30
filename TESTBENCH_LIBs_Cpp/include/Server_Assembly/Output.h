#pragma once

namespace Avril_FSD
{
    class Output
    {
    public:
        Output();
        virtual ~Output();
        void Initialise_Control();

        class Output_Control* Get_Control_Of_Output();
        class Object* Get_OutputBuffer_Subset();
        __int8 GetPraiseEventId();

        void SetPraiseEventId(__int8 value);

        void Set_OutputBuffer_Subset(class Praise0_Output* praise0_value);
        void Set_OutputBuffer_Subset(class Praise1_Output* praise0_value);
        void Set_OutputBuffer_Subset(class Praise2_Output* praise0_value);
        

    protected:

    private:
        static void Set_control_Of_Output(class Output_Control* output_Control);
    };
}