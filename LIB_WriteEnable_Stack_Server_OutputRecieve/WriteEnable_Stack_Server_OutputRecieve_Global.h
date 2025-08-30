#pragma once
#include <array>

namespace Avril_FSD
{
    class WriteEnableStack_ServerOutputRecieve_Global
    {
    public:
        WriteEnableStack_ServerOutputRecieve_Global();
        ~WriteEnableStack_ServerOutputRecieve_Global();
        unsigned char Get_NumCores();
        bool GetConst_Write_IDLE(unsigned char index);
        bool GetConst_Write_WAIT(unsigned char index);
        bool GetConst_Write_WRITE(unsigned char index);
    };
}

