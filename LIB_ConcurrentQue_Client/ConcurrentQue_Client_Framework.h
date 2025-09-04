#pragma once

namespace Avril_FSD
{
    class ConcurrentQue_Client_Framework
    {
    public:
        ConcurrentQue_Client_Framework();
        virtual ~ConcurrentQue_Client_Framework();
        void Request_Wait_Launch(unsigned char concurrent_CoreId);
        void Thread_End(unsigned char concurrent_CoreId);
        static class ConcurrentQue_Client_LaunchConcurrency* Get_ConcurrentQue();

    private:
        static void Create_ConcurrentQue();
        static void Set_ConcurrentQue(class ConcurrentQue_Client_LaunchConcurrency* concurrentQue);
    };
}