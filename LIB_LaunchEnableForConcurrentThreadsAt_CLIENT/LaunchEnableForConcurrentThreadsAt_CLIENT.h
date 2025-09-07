#pragma once

namespace Avril_FSD
{
    class LaunchEnableForConcurrentThreadsAt_END
    {
    public:
        LaunchEnableForConcurrentThreadsAt_END();
        virtual ~LaunchEnableForConcurrentThreadsAt_END();
        void Initialise_Control();
        void Thread_Start(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId);
        void Thread_End(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId);

        class LaunchEnableForConcurrentThreadsAt_END_Global* Get_LaunchConcurrency_Global();
        class LaunchEnableForConcurrentThreadsAt_END_Control* Get_Control_Of_LaunchConcurrency();

    private:
        static void Create_LaunchEnableForConcurrentThreadsAt_END_Global();
        static void Create_Control_Of_LaunchConcurrency();

        static class LaunchEnableForConcurrentThreadsAt_END_Global* Get__LaunchConcurrency_Global();
        static class LaunchEnableForConcurrentThreadsAt_END_Control* Get__Control_Of_LaunchConcurrency();

        static void Set_LaunchConcurrency_Global(LaunchEnableForConcurrentThreadsAt_END_Global* global);
        static void Set_Control_Of_LaunchConcurrency(class LaunchEnableForConcurrentThreadsAt_END_Control* control);
    };
}