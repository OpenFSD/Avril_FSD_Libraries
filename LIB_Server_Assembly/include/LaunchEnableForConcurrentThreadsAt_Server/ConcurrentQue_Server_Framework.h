#pragma once

namespace Avril_FSD
{
    class ConcurrentQue_Server_Framework
    {
    public:
        ConcurrentQue_Server_Framework();
        virtual ~ConcurrentQue_Server_Framework();
        static class ConcurrentQue_Server* Get_ConcurrentQue();

    private:
        static void Create_ConcurrentQue();
        //static class ConcurrentQue_Server* Get__ConcurrentQue();
        static void Set_ConcurrentQue(class ConcurrentQue_Server* concurrentQue);
    };
}