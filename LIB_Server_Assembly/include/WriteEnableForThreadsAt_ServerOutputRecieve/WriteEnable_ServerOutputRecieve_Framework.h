#pragma once

namespace Avril_FSD
{
    class WriteEnable_ServerOutputRecieve_Framework
    {
    public:
        WriteEnable_ServerOutputRecieve_Framework();
        virtual ~WriteEnable_ServerOutputRecieve_Framework();
        class WriteEnable_ServerOutputRecieve* Get_writeEnable();

    private:
        static void Set_writeEnable(class WriteEnable_ServerOutputRecieve* writeEnable);
    };
}