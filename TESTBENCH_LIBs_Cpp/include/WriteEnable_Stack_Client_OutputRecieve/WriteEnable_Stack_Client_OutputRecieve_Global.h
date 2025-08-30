#pragma once
#include <array>

namespace Avril_FSD
{
    class WriteEnable_Stack_Client_OutputRecieve_Global
    {
    public:
        WriteEnable_Stack_Client_OutputRecieve_Global();
        ~WriteEnable_Stack_Client_OutputRecieve_Global();
        unsigned char Get_NumCores();
        bool GetConst_Write_IDLE(unsigned char index);
        bool GetConst_Write_WAIT(unsigned char index);
        bool GetConst_Write_WRITE(unsigned char index);
    };
}

