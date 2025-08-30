#pragma once

namespace Avril_FSD
{
    class WriteEnableStack_ServerOutputRecieve
    {
    public:
        WriteEnableStack_ServerOutputRecieve();
        virtual ~WriteEnableStack_ServerOutputRecieve();
        void Initialise_Control();
        void Write_End(unsigned char coreId);
        void Write_Start(unsigned char coreId);

    private:
        static class WriteEnableStack_ServerOutputRecieve_Global* Get_global();
        static class WriteEnableStack_ServerOutputRecieve_Control* Get_writeEnable_Control();

        static void Set_global(class WriteEnableStack_ServerOutputRecieve_Global* global);
        static void Set_writeEnable_Control(class WriteEnableStack_ServerOutputRecieve_Control* writeEnableControl);
    };
}
