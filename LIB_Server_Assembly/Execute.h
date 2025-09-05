#pragma once
#include <array>
#include <thread>

namespace Avril_FSD
{
    class Execute
    {
    public:
        Execute();
        virtual ~Execute();
        void Initialise(class Avril_FSD::Framework_Server* obj);
        void Initialise_Control(__int8 number_Implemented_Cores);
        void Initialise_Libraries();
        void Initialise_Threads(class Avril_FSD::Framework_Server* obj);

        static class Execute_Control* Get_Control_Of_Execute();
        static class ConcurrentQue_Server_Framework* Get_Program_ConcurrentQue_Server();
        static class WriteEnable_ServerInputAction_Framework* Get_Program_WriteEnable_ServerInputAction();
        static class WriteEnable_ServerOutputRecieve_Framework* Get_Program_WriteEnable_ServerOutputRecieve();

    private:
        static void Set_Control_Of_Execute(class Execute_Control* execute_Control);
    };
}