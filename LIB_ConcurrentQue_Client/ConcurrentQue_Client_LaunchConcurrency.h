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
        static void Create_ConcurrentQue_Client_Global();
        static void Create_Control_Of_LaunchConcurrency();

        static class ConcurrentQue_Client_Global* Get_class_LaunchConcurrency_Global();
        static class ConcurrentQue_Client_LaunchConcurrency_Control* Get_class_Control_Of_LaunchConcurrency();

        static void Set_LaunchConcurrency_Global(ConcurrentQue_Client_Global* global);
        static void Set_Control_Of_LaunchConcurrency(class ConcurrentQue_Client_LaunchConcurrency_Control* control);
    };
}