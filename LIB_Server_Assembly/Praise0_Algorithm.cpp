#include "pch.h"

#include <cstddef>

Avril_FSD::Praise0_Algorithm::Praise0_Algorithm()
{
}

Avril_FSD::Praise0_Algorithm::~Praise0_Algorithm()
{
}

void Avril_FSD::Praise0_Algorithm::Do_Praise(class Avril_FSD::Praise0_Input* ptr_In_SubSet, class Avril_FSD::Praise0_Output* ptr_Out_SubSet)
{
        ptr_Out_SubSet->Set_ping_Active(ptr_In_SubSet->Get_ping_Active());
}
