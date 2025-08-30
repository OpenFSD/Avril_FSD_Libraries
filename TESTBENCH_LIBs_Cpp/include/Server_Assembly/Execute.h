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
        void Initialise_Threads();
        void Initialise_Libraries();
        static class Execute_Control* Get_Control_Of_Execute();

    private:
        static void Set_Control_Of_Execute(class Execute_Control* execute_Control);
    };
}