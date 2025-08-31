
namespace Avril_FSD_ServerAssembly
{
    static class Program
    {
        static void Main()
        {
            System.Console.WriteLine("Launched Program.");//TestBench
            Avril_FSD_ServerAssembly.Framework framework = new Avril_FSD_ServerAssembly.Framework();
            while (framework == null) { }
            System.Console.WriteLine("Created APP_Server => framework.");//TestBench
            Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().Initialise_Libraries();
            System.Console.WriteLine("created => APP_Server Libraries.");//TestBench
        }
    }
}