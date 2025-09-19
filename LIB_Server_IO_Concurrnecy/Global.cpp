#include "pch.h"

__int8 Avril_FSD::Global::number_Implemented_Cores = NULL;
__int8 Avril_FSD::Global::number_Praise_Events = NULL;

Avril_FSD::Global::Global()
{
    number_Implemented_Cores = __int8(4);//NUMBER OF CORES
    number_Praise_Events = __int8(3);
}

Avril_FSD::Global::~Global()
{
        
}

__int8 Avril_FSD::Global::Get_NumCores()
{
    return number_Implemented_Cores;
}
__int8 Avril_FSD::Global::Get_NumPraiseEvetns()
{
    return number_Praise_Events;
}
