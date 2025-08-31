#pragma once

namespace Avril_FSD
{
    class Framework_Server
    {
    public:
        Framework_Server();
        virtual ~Framework_Server();
        static class Server* Get_Server_Assembly();

    private:
        static void Set_Server_Assembly(class Server* server);
    };
}