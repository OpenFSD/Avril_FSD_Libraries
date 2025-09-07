#pragma once

namespace Avril_FSD
{
    class WriteEnable_ClientOutputRecieve
    {
    public:
        WriteEnable_ClientOutputRecieve();
        virtual ~WriteEnable_ClientOutputRecieve();
        void Initialise_Control();

        void Write_End(class WriteEnable_ClientOutputRecieve_Framework* obj, unsigned char coreId);
        void Write_Start(class WriteEnable_ClientOutputRecieve_Framework* obj, unsigned char coreId);

        static class WriteEnable_ClientOutputRecieve_Global* Get_global();
        static class WriteEnable_ClientOutputRecieve_Control* Get_writeEnable_Control();

    private:
        static void Set_global(class WriteEnable_ClientOutputRecieve_Global* global);
        static void Set_writeEnable_Control(class WriteEnable_ClientOutputRecieve_Control* writeEnableControl);
    };
}
