using System;

namespace TESTBENCH_LIBs_Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            IntPtr concurrentQue_END_Framework = Avril_FSD.Library_For_Concurrent_Que_On_Client.Initialise_ConcurrentQue();
            byte launchCoreId = Avril_FSD.Library_For_Concurrent_Que_On_Client.Get_coreId_To_Launch(concurrentQue_END_Framework);
            
            
            
            
            
            //IntPtr serverAssembly = Avril_FSD.Library_For_Server_Assembly.Initialise_Server_Assembly();
            
        }
    }
}
