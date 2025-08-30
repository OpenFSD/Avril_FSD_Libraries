#pragma once

namespace Avril_FSD
{
    class WriteEnable_Stack_Server_InputAction
    {
    public:
        WriteEnable_Stack_Server_InputAction();
        virtual ~WriteEnable_Stack_Server_InputAction();
        void Initialise_Control();
        void Write_End(unsigned char coreId);
        void Write_Start(unsigned char coreId);

    private:
        static class WriteEnable_Stack_Server_InputAction_Global* Get_global();
        static class WriteEnable_Stack_Server_InputAction_Control* Get_writeEnable_Control();

        static void Set_global(class WriteEnable_Stack_Server_InputAction_Global* global);
        static void Set_writeEnable_Control(class WriteEnable_Stack_Server_InputAction_Control* writeEnableControl);
    };
}
