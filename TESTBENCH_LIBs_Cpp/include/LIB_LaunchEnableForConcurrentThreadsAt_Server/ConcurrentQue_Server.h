#pragma once

namespace Avril_FSD
{
    class ConcurrentQue_Server
    {
    public:
        ConcurrentQue_Server();
        virtual ~ConcurrentQue_Server();
        void Initialise_Control();
        void Thread_Start(class Avril_FSD::ConcurrentQue_Server_Framework* obj, unsigned char concurrent_CoreId);
        void Thread_End(class Avril_FSD::ConcurrentQue_Server_Framework* obj, unsigned char concurrent_CoreId);

        static class ConcurrentQue_Server_Global* Get_LaunchConcurrency_Global();
        static class ConcurrentQue_Server_Control* Get_Control_Of_LaunchConcurrency();

    private:
        static void Create_ConcurrentQue_Server_Global();
        static void Create_Control_Of_LaunchConcurrency();

        //static class ConcurrentQue_Server_Global* Get__LaunchConcurrency_Global();
        //static class ConcurrentQue_Server_Control* Get__Control_Of_LaunchConcurrency();

        static void Set_LaunchConcurrency_Global(ConcurrentQue_Server_Global* global);
        static void Set_Control_Of_LaunchConcurrency(class ConcurrentQue_Server_Control* control);
    };
}