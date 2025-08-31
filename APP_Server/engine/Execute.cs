using System.Threading;

namespace Avril_FSD_ServerAssembly
{ 
    public class Execute
    {
        static private Avril_FSD_ServerAssembly.Execute_Control _execute_Control = null;

        Thread _input_Listen = null;
        Thread _output_Send = null;

        public Execute()
        {

        }
        public void Initialise_APP_Server()
        {
            Avril_FSD_ServerAssembly.Framework.GetGameServer().GetAlgorithms().Initialise(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetGlobal().Get_NumCores());
        }
        public void Initialise_Control(byte numberOfCores, Global global)
        {
            Set_Execute_Control(new Avril_FSD_ServerAssembly.Execute_Control(numberOfCores));
            while (Get_Execute_Control() == null) { /* Wait while is created */ }
        }
        public void Initialise_Threads()
        {
            Set_input_Listen(new Thread(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetAlgorithms().GetIO_ListenRespond().Thread_Input_Listen));
            Get_input_Listen().Start();

            Set_output_Send(new Thread(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetAlgorithms().GetIO_ListenRespond().Thread_Output_Send));
            Get_output_Send().Start();
        }
        public void Initialise_Libraries()
        {
            var serverAssembly = Avril_FSD.Library_For_Server_Assembly.Initialise_Server_Assembly();
            System.Console.WriteLine("created => Avril_FSD.Library_For_Server_Assembly");//TestBench
        }
        public void Create_And_Run_Graphics()
        {
            using (Avril_FSD_ServerAssembly.Game_Instance gameInstance = new Avril_FSD_ServerAssembly.Game_Instance())
            {
                gameInstance.Run(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().Get_settings().Get_refreshRate());
            }
        }

        public Execute_Control Get_Execute_Control()
        {
            return _execute_Control;
        }
        public Thread Get_input_Listen()
        {
            return _input_Listen;
        }
        public Thread Get_output_Send()
        {
            return _output_Send;
        }

        private void Set_Execute_Control(Execute_Control executeControl)
        {
            _execute_Control = executeControl;
        }
        private void Set_input_Listen(Thread inputListen)
        {
            _input_Listen = inputListen;
        }
        private void Set_output_Send(Thread outputSend)
        {
            _output_Send = outputSend;
        }
    }
}