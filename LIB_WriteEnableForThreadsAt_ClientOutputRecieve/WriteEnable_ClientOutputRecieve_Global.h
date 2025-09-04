#pragma once
#include <array>
#include <vector>

namespace Avril_FSD
{
    class WriteEnable_ClientOutputRecieve_Global
    {
    public:
        WriteEnable_ClientOutputRecieve_Global();
        ~WriteEnable_ClientOutputRecieve_Global();
        unsigned char Get_NumCores();
        std::vector<bool> Get_flag_write_IDLE();
        std::vector<bool> Get_flag_write_WAIT();
        std::vector<bool> Get_flag_write_WRITE();
    };
}

