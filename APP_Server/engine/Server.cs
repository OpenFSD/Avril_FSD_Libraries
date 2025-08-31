namespace Avril_FSD_ServerAssembly
{
    public class Server
    {
        static private Avril_FSD_ServerAssembly.Algorithms _algorithms = null;
        static private Avril_FSD_ServerAssembly.Data _data = null;
        static private Avril_FSD_ServerAssembly.Execute _execute = null;
        static private Avril_FSD_ServerAssembly.Global _global = null;

        public Server()
        {
            SetGlobal(new Avril_FSD_ServerAssembly.Global());
            while (GetGlobal() == null) { /* Wait while is created */ }

            SetAlgorithms(new Avril_FSD_ServerAssembly.Algorithms(GetGlobal().Get_NumCores()));
            while (GetAlgorithms() == null) { /* Wait while is created */ }

            SetData(new Avril_FSD_ServerAssembly.Data());
            while (GetData() == null) { /* Wait while is created */ }
            GetData().InitialiseControl();

            SetExecute(new Avril_FSD_ServerAssembly.Execute());
            while (GetExecute() == null) { /* Wait while is created */ }
            GetExecute().Initialise_Control(GetGlobal().Get_NumCores(), GetGlobal());

            System.Console.WriteLine("Avril_FSD_ServerAssembly: Server");
        }

        public Avril_FSD_ServerAssembly.Algorithms GetAlgorithms()
        {
            return _algorithms;
        }
        public Avril_FSD_ServerAssembly.Data GetData()
        {
            return _data;
        }
        public Avril_FSD_ServerAssembly.Global GetGlobal()
        {
            return _global;
        }
        public Avril_FSD_ServerAssembly.Execute GetExecute()
        {
            return _execute;
        }
        private void SetAlgorithms(Avril_FSD_ServerAssembly.Algorithms algorithms)
        {
            _algorithms = algorithms;
        }
        private void SetData(Avril_FSD_ServerAssembly.Data data)
        {
            _data = data;
        }
        private void SetGlobal(Avril_FSD_ServerAssembly.Global global)
        {
            _global = global;
        }
        private void SetExecute(Avril_FSD_ServerAssembly.Execute execute)
        {
            _execute = execute;
        }
    }
}