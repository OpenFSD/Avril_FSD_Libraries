#pragma once

namespace Avril_FSD
{
    class ConcurrentQue_Client_LaunchConcurrency
    {
    public:
        ConcurrentQue_Client_LaunchConcurrency();
        virtual ~ConcurrentQue_Client_LaunchConcurrency();
        void Initialise_Control();
        void Thread_Start(unsigned char concurrent_CoreId);
        void Thread_End(unsigned char concurrent_CoreId);

        class ConcurrentQue_Client_Global* Get_LaunchConcurrency_Global();
        class ConcurrentQue_Client_LaunchConcurrency_Control* Get_Control_Of_LaunchConcurrency();

    private:
        void Create_ConcurrentQue_Client_Global();
        void Create_Control_Of_LaunchConcurrency();

        void Set_LaunchConcurrency_Global(ConcurrentQue_Client_Global* global);
        void Set_Control_Of_LaunchConcurrency(class ConcurrentQue_Client_LaunchConcurrency_Control* control);
    };
}