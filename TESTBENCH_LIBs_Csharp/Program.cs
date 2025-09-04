using System;

namespace TESTBENCH_LIBs_Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Started TESTBENCH.");
            IntPtr programId_ConcurrentQue = Avril_FSD.Library_For_Concurrent_END.Initialise_ConcurrentQue();

            IntPtr programId_WriteQue = Avril_FSD.Library_For_WriteEnable_STACK.Initialise_WriteEnable();
        }
    }
}
