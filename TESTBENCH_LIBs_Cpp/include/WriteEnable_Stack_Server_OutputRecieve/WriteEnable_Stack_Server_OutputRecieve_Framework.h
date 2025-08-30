#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <bitset>

namespace Avril_FSD
{
    class WriteEnableStack_ServerOutputRecieve_Framework
    {
    public:
        WriteEnableStack_ServerOutputRecieve_Framework();
        virtual ~WriteEnableStack_ServerOutputRecieve_Framework();

        static void Write_End(unsigned char coreId);
        static void Write_Start(unsigned char coreId);

    private:
        static class WriteEnableStack_ServerOutputRecieve* Get_writeEnable();
        static void Set_writeEnable(class WriteEnableStack_ServerOutputRecieve* writeEnable);
    };
}