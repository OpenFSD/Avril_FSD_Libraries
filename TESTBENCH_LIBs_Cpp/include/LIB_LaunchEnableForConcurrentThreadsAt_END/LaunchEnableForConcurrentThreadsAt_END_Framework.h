#pragma once

namespace Avril_FSD
{
    class LaunchEnableForConcurrentThreadsAt_END_Framework
    {
    public:
        LaunchEnableForConcurrentThreadsAt_END_Framework();
        virtual ~LaunchEnableForConcurrentThreadsAt_END_Framework();
        class LaunchEnableForConcurrentThreadsAt_END* Get_LaunchEnableForConcurrentThread();

    private:
        static void Create_LaunchEnableForConcurrentThreadsAt();
        static class LaunchEnableForConcurrentThreadsAt_END* Get__LaunchEnableForConcurrentThreadsAt();
        static void Set_LaunchEnableForConcurrentThreadsAt(class LaunchEnableForConcurrentThreadsAt_END* concurrentQue);
    };
}