#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <bitset>

namespace Avril_FSD
{
    class WriteEnableStack_ServerInputAction_Framework
    {
    public:
        WriteEnableStack_ServerInputAction_Framework();
        virtual ~WriteEnableStack_ServerInputAction_Framework();

        static void Write_End(unsigned char coreId);
        static void Write_Start(unsigned char coreId);

    private:
        static class WriteEnable_Stack_Server_InputAction* Get_writeEnable();
        static void Set_writeEnable(class WriteEnable_Stack_Server_InputAction* writeEnable);
    };
}