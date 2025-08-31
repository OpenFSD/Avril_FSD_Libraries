#pragma once

namespace Avril_FSD
{
    class Praise1_Algorithm
    {
    public:
        Praise1_Algorithm();
        virtual ~Praise1_Algorithm();
        void Do_Praise(class Praise1_Input* ptr_In_SubSet, class Praise1_Output* ptr_Out_SubSet);
    };
}