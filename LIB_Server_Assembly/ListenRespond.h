#pragma once

namespace Avril_FSD
{
    class ListenRespond
    {
    public:
        ListenRespond();
        virtual ~ListenRespond();
        static void IO_ListenRespond(class Avril_FSD::Framework_Server* obj);
 
    protected:

    private:
        static void ThreadForListen(class Avril_FSD::Framework_Server* obj);
        static void ThreadForRespond(class Avril_FSD::Framework_Server* obj);

        static __int8 Get_thisThreadCoreId();

        static void Set_listen_CoreId(__int8 thisThreadCoreId);
    };
}