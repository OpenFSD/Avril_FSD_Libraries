#pragma once
#include <array>

namespace Avril_FSD
{
    class ConcurrentQue_Server_Global
    {
    public:
        ConcurrentQue_Server_Global();
        ~ConcurrentQue_Server_Global();
        bool GetConst_Core_IDLE();
        bool GetConst_Core_ACTIVE();
        unsigned char Get_NumCores();
    };
}
