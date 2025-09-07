#pragma once
#include <array>
#include <vector>

namespace Avril_FSD
{
    class WriteEnableForThreadsAt_STACK_Global
    {
    public:
        WriteEnableForThreadsAt_STACK_Global();
        ~WriteEnableForThreadsAt_STACK_Global();
        unsigned char Get_NumCores();
        std::vector<bool> Get_flag_write_IDLE();
        std::vector<bool> Get_flag_write_WAIT();
        std::vector<bool> Get_flag_write_WRITE();
    };
}

