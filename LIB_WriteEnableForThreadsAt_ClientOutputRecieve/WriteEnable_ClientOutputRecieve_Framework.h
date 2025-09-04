#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <bitset>

namespace Avril_FSD
{
    class WriteEnable_ClientOutputRecieve_Framework
    {
    public:
        WriteEnable_ClientOutputRecieve_Framework();
        virtual ~WriteEnable_ClientOutputRecieve_Framework();
        class WriteEnable_ClientOutputRecieve* Get_writeEnable();

    private:
        static void Set_writeEnable(class WriteEnable_ClientOutputRecieve* writeEnable);
    };
}