#include "pch.h"

#include <cstddef>

bool flag_core_ACTIVE = NULL;
bool flag_core_IDLE = NULL;
unsigned char number_Implemented_Cores = NULL;

Avril_FSD::ConcurrentQue_Server_Global::ConcurrentQue_Server_Global()
{
    flag_core_ACTIVE = bool(true);
    flag_core_IDLE = bool(false);

    number_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
}

Avril_FSD::ConcurrentQue_Server_Global::~ConcurrentQue_Server_Global()
{

}

bool Avril_FSD::ConcurrentQue_Server_Global::GetConst_Core_ACTIVE()
{
    return flag_core_ACTIVE;
}
bool Avril_FSD::ConcurrentQue_Server_Global::GetConst_Core_IDLE()
{
    return flag_core_IDLE;
}
unsigned char Avril_FSD::ConcurrentQue_Server_Global::Get_NumCores()
{
    return number_Implemented_Cores;
}