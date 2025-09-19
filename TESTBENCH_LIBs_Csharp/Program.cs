using System;

namespace TESTBENCH_LIBs_Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("started TESTBENCH.");
            IntPtr program_ServerConcurrnecy = Avril_FSD.Library_For_Server_Concurrency.Initialise_Server_Concurrency();
            //IntPtr programId_ConcurrentQue = Avril_FSD.Library_For_LaunchEnableForConcurrentThreadsAt_Client.Initialise_LaunchEnableForConcurrentThreadsAt();
            Console.WriteLine("created concurrent que on client.");
            //IntPtr programId_WriteQue = Avril_FSD.Library_For_WriteEnableForThreadsAt_ClientOutputRecieve.Initialise_WriteEnable();
            Console.WriteLine("created write enable que for client output recieve.");

            Console.WriteLine("end TESTBENCH.");
            while (true) { }
        }
    }
}
