#pragma once
#include <array>

namespace Avril_FSD
{
    class WriteEnable_Stack_Server_InputAction_Global
    {
    public:
        WriteEnable_Stack_Server_InputAction_Global();
        ~WriteEnable_Stack_Server_InputAction_Global();
        unsigned char Get_NumCores();
        bool GetConst_Write_IDLE(unsigned char index);
        bool GetConst_Write_WAIT(unsigned char index);
        bool GetConst_Write_WRITE(unsigned char index);
    };
}

