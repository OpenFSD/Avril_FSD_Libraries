#pragma once
#include <array>
#include <thread>

namespace Avril_FSD
{
    class Execute
    {
    public:
        Execute(class Global* ptr_Global, __int8 number_Implemented_Cores);
        virtual ~Execute();
        void Initialise();
        void Initialise_Control(__int8 number_Implemented_Cores, class Global* ptr_Global);
        void Initialise_Libraries();
        void Initialise_Threads();
        static class Execute_Control* Get_Control_Of_Execute();
        static class ConcurrentQue_Server_Framework* Get_ConcurrentQue_Server_Framework();
        static class WriteEnableStack_ServerInputAction_Framework* Get_WriteEnableStack_ServerInputAction_Framework();
        static class WriteEnableStack_ServerOutputRecieve_Framework* Get_WriteEnableStack_ServerOutputRecieve_Framework();

    private:
        static void Set_Control_Of_Execute(class Execute_Control* execute_Control);
    };
}