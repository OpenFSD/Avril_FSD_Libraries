#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <bitset>

namespace Avril_FSD
{
    class WriteEnable_ServerOutputRecieve_Framework
    {
    public:
        WriteEnable_ServerOutputRecieve_Framework();
        virtual ~WriteEnable_ServerOutputRecieve_Framework();
        class WriteEnable_ServerOutputRecieve* Get_writeEnable();

    private:
        static void Set_writeEnable(class WriteEnable_ServerOutputRecieve* writeEnable);
    };
}