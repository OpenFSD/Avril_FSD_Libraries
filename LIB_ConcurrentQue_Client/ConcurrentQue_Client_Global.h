#pragma once
#include <array>

namespace Avril_FSD
{
    class ConcurrentQue_Client_Global
    {
    public:
        ConcurrentQue_Client_Global();
        ~ConcurrentQue_Client_Global();
        bool GetConst_Core_IDLE();
        bool GetConst_Core_ACTIVE();
        unsigned char Get_NumCores();
    };
}
