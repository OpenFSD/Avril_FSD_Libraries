#include "pch.h"

#include <cstddef>

bool flag_write_IDLE[2] = { NULL, NULL };
bool flag_write_WAIT[2] = { NULL, NULL };
bool flag_write_WRITE[2] = { NULL, NULL };
unsigned char ptr_num_Implemented_Cores = NULL;

Avril_FSD::WriteEnableStack_ServerOutputRecieve_Global::WriteEnableStack_ServerOutputRecieve_Global()
{
    flag_write_IDLE[0] = bool(false);
    flag_write_IDLE[1] = bool(false);

    flag_write_WAIT[0] = bool(false);
    flag_write_WAIT[1] = bool(true);

    flag_write_WRITE[0] = bool(true);
    flag_write_WRITE[1] = bool(false);

    ptr_num_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
}

Avril_FSD::WriteEnableStack_ServerOutputRecieve_Global::~WriteEnableStack_ServerOutputRecieve_Global()
{
    delete flag_write_IDLE;
    delete flag_write_WAIT;
    delete flag_write_WRITE;
}

unsigned char Avril_FSD::WriteEnableStack_ServerOutputRecieve_Global::Get_NumCores()
{
    return ptr_num_Implemented_Cores;
}
bool Avril_FSD::WriteEnableStack_ServerOutputRecieve_Global::GetConst_Write_IDLE(unsigned char index)
{
    return flag_write_IDLE[index];
}
bool Avril_FSD::WriteEnableStack_ServerOutputRecieve_Global::GetConst_Write_WAIT(unsigned char index)
{
    return flag_write_WAIT[index];
}
bool Avril_FSD::WriteEnableStack_ServerOutputRecieve_Global::GetConst_Write_WRITE(unsigned char index)
{
    return flag_write_WRITE[index];
}