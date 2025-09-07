#pragma once

namespace Avril_FSD
{
    class WriteEnableForThreadsAt_STACK
    {
    public:
        WriteEnableForThreadsAt_STACK();
        virtual ~WriteEnableForThreadsAt_STACK();
        void Initialise_Control();

        void Write_End(class WriteEnableForThreadsAt_STACK_Framework* obj, unsigned char coreId);
        void Write_Start(class WriteEnableForThreadsAt_STACK_Framework* obj, unsigned char coreId);

        class WriteEnableForThreadsAt_STACK_Global* Get_global();
        class WriteEnableForThreadsAt_STACK_Control* Get_writeEnable_Control();

    private:
        static void Set_global(class WriteEnableForThreadsAt_STACK_Global* global);
        static void Set_writeEnable_Control(class WriteEnableForThreadsAt_STACK_Control* writeEnableControl);
    };
}
