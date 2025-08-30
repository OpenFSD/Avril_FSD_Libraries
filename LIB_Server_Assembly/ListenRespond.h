#pragma once

namespace Avril_FSD
{
    class ListenRespond
    {
    public:
        ListenRespond();
        virtual ~ListenRespond();
        static void IO_ListenRespond();
 
    protected:

    private:
        static void ThreadForListen(Server* serverAssembly);
        static void ThreadForRespond(Server* serverAssembly);

        static __int8 Get_thisThreadCoreId();

        static void Set_listen_CoreId(__int8 thisThreadCoreId);
    };
}