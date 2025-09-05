#pragma once

namespace Avril_FSD
{
    class WriteEnable_ServerInputAction_Framework
    {
    public:
        WriteEnable_ServerInputAction_Framework();
        virtual ~WriteEnable_ServerInputAction_Framework();
        class WriteEnable_ServerInputAction* Get_writeEnable();

    private:
        static void Set_writeEnable(class WriteEnable_ServerInputAction* writeEnable);
    };
}