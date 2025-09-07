#pragma once

namespace Avril_FSD
{
    class WriteEnable_ServerOutputRecieve
    {
    public:
        WriteEnable_ServerOutputRecieve();
        virtual ~WriteEnable_ServerOutputRecieve();
        void Initialise_Control();

        void Write_End(class WriteEnable_ServerOutputRecieve_Framework* obj, unsigned char coreId);
        void Write_Start(class WriteEnable_ServerOutputRecieve_Framework* obj, unsigned char coreId);

        static class WriteEnable_ServerOutputRecieve_Global* Get_global();
        static class WriteEnable_ServerOutputRecieve_Control* Get_writeEnable_Control();

    private:
        static void Set_global(class WriteEnable_ServerOutputRecieve_Global* global);
        static void Set_writeEnable_Control(class WriteEnable_ServerOutputRecieve_Control* writeEnableControl);
    };
}
