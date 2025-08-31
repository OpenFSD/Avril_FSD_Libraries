
namespace Avril_FSD_ServerAssembly
{
    public class Framework
    {
        static private Avril_FSD_ServerAssembly.Server _game_server = null;

        public Framework()
        {
            System.Console.WriteLine("entered => Avril_FSD_ServerAssembly.Framework()");//TestBench

            Set_GameServer(new Avril_FSD_ServerAssembly.Server());
            while (GetGameServer() == null) { }
            GetGameServer().GetExecute().Initialise_APP_Server();
            System.Console.WriteLine("created => Avril_FSD_ServerAssembly.Server()");//TestBench

            //GetGameServer().GetExecute().Initialise_Libraries();
            



            //GetGameServer().GetExecute().Initialise_Threads();//todo

            //Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().Create_And_Run_Graphics();
            //System.Console.WriteLine("skipped => Valve.Networking()");//TestBench
        }

        static public Avril_FSD_ServerAssembly.Server GetGameServer()
        {
            return _game_server;
        }
        static private void Set_GameServer(Avril_FSD_ServerAssembly.Server server)
        {
            _game_server = server;
        }

    }
}
