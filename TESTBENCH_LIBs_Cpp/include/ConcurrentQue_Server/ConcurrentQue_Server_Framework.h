#pragma once

namespace Avril_FSD
{
    class ConcurrentQue_Server_Framework
    {
    public:
        ConcurrentQue_Server_Framework();
        virtual ~ConcurrentQue_Server_Framework();
        static void Request_Wait_Launch(unsigned char concurrent_CoreId);
        static void Thread_End(unsigned char concurrent_CoreId);
        
        static unsigned char Get_coreId_To_Launch();
        static bool Get_Flag_Active();
        static bool Get_Flag_ConcurrentCoreState(unsigned char concurrent_CoreId);
        static bool Get_Flag_Idle();
        static bool Get_State_LaunchBit();

        static void SetFlag_ConcurrentCoreState(unsigned char concurrent_CoreId, bool value);

    private:
        static void Create_ConcurrentQue();
        static class ConcurrentQue_Server_LaunchConcurrency* Get_ConcurrentQue();
        static void Set_ConcurrentQue(class ConcurrentQue_Server_LaunchConcurrency* concurrentQue);
    };
}