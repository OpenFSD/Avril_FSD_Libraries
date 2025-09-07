#pragma once

namespace Avril_FSD
{
    class WriteEnableForThreadsAt_STACK_Framework
    {
    public:
        WriteEnableForThreadsAt_STACK_Framework();
        virtual ~WriteEnableForThreadsAt_STACK_Framework();
        class WriteEnableForThreadsAt_STACK* Get_writeEnable();

    private:
        static void Set_writeEnable(class WriteEnableForThreadsAt_STACK* writeEnable);
    };
}