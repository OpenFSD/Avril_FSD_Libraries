
namespace Avril_FSD_ServerAssembly
{
    public class Framework
    {
        static private Avril_FSD_ServerAssembly.Server game_server = null;
        //static private Valve.Networking networkingServer = null;

        public Framework()
        {
            System.Console.WriteLine("entered => Avril_FSD_ServerAssembly.Framework()");//TestBench

            game_server = new Avril_FSD_ServerAssembly.Server();
            while (game_server == null) { /* Wait whileis created */ }
            game_server.GetExecute().Initialise();
            System.Console.WriteLine("created => Avril_FSD_ServerAssembly.Server()");//TestBench

            Avril_FSD.Library.Create_Hosting_Server();
            System.Console.WriteLine("created => Server_Library.Framework_Server()");//TestBench

            game_server.GetExecute().Initialise_Threads();//todo

            //Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().Create_And_Run_Graphics();

            System.Console.WriteLine("skipped => Valve.Networking()");//TestBench
        }

        static public Avril_FSD_ServerAssembly.Server GetGameServer()
        {
            return game_server;
        }

        /*
        static public Valve.Networking GetNetworkingServer()
        {
             return networkingServer;
        }
        */
    }
}
