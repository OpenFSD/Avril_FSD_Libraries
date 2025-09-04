#pragma once

namespace Avril_FSD
{
    class ConcurrentQue_CLIENT_Framework
    {
    public:
        ConcurrentQue_CLIENT_Framework();
        virtual ~ConcurrentQue_CLIENT_Framework();
        static class ConcurrentQue_CLIENT* Get_ConcurrentQue();

    private:
        static void Create_ConcurrentQue();
        //static class ConcurrentQue_CLIENT* Get__ConcurrentQue();
        static void Set_ConcurrentQue(class ConcurrentQue_CLIENT* concurrentQue);
    };
}