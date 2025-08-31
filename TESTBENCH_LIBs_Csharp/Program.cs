
namespace TESTBENCH_LIBs_Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var serverAssembly = Avril_FSD.Library_For_Server_Assembly.Initialise_Server_Assembly();
            Avril_FSD.Library_For_Server_Assembly.GetFlag_Avril_FSD_Initialised();
        }
    }
}
