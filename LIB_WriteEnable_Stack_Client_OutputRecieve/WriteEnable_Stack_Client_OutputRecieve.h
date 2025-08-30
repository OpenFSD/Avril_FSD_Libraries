#pragma once

namespace Avril_FSD
{
    class WriteEnable_Stack_Client_OutputRecieve
    {
    public:
        WriteEnable_Stack_Client_OutputRecieve();
        virtual ~WriteEnable_Stack_Client_OutputRecieve();
        void Initialise_Control();

        void Write_End(unsigned char coreId);
        void Write_Start(unsigned char coreId);

    private:
        static class WriteEnable_Stack_Client_OutputRecieve_Global* Get_global();
        static class WriteEnable_Stack_Client_OutputRecieve_Control* Get_writeEnable_Control();

        static void Set_global(class WriteEnable_Stack_Client_OutputRecieve_Global* global);
        static void Set_writeEnable_Control(class WriteEnable_Stack_Client_OutputRecieve_Control* writeEnableControl);
    };
}
