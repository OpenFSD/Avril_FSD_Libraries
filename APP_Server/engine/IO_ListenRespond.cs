using System.Collections;
using System.Collections.Concurrent;

namespace Avril_FSD_ServerAssembly
{
    public class IO_ListenRespond
    {
        byte listen_CoreId;
        byte respond_CoreId;
        Avril_FSD_ServerAssembly.IO_ListenRespond_Control io_Control;

        public IO_ListenRespond()
        {
            listen_CoreId = 255;
            respond_CoreId = 255;
            io_Control = null;
        }
        public void InitialiseControl()
        {
            io_Control = new Avril_FSD_ServerAssembly.IO_ListenRespond_Control();
            while (io_Control == null) { /* Wait while is created */ }
        }

        public void Thread_Input_Listen()
        {/*
            listen_CoreId = 0;
            bool done_once = true;
            while (Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().GetExecute_Control().GetFlag_ThreadInitialised(listen_CoreId) == true)
            {
                if (done_once == true)
                {
                    Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().GetExecute_Control().SetFlag_ThreadInitialised(listen_CoreId);
                    done_once = false;
                }
            }
            System.Console.WriteLine("Thread Initialised => Thread_Input_Listen()");//TestBench
            while (Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().GetExecute_Control().GetFlag_Server_Shell_Initialised() == true)
            {
            
            }
            System.Console.WriteLine("Thread Started => Thread_Input_Listen()");//TestBench
            while (Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().GetExecute_Control().GetFlag_Server_Shell_Initialised() == false)
            {
                //Valve.Networking.CopyPayloadFromMessage();//todo
                Avril_FSD_ServerAssembly.Library.ServerCallTo_Flip_InBufferToWrite();
                Avril_FSD_ServerAssembly.WriteEnable.ServerCallTo_Request_Write_Stack_Server_InputAction(0);
                Avril_FSD_ServerAssembly.Library.ServerCallTo_Push_Stack_InputPraises();
                switch (Avril_FSD_ServerAssembly.Library.ServerCallTo_Get_State_OfCoreToLaunch())
                {
                case false://IDLE
                    Avril_FSD_ServerAssembly.ConcurrentQue.ServerCallTo_Request_Wait_Launch_ConcurrentThread();
                    break;

                case true://ACTIVE  

                    break;
                }
                Avril_FSD_ServerAssembly.WriteEnable.ServerCallTo_End_Write_Stack_Server_InputAction(0);
            }
       */ }

        public void Thread_Output_Send()
        {/*
            respond_CoreId = 1;
            bool done_once = true;
            while (Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().GetExecute_Control().GetFlag_ThreadInitialised(1) == true)
            {
                if (done_once == true)
                {
                    Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().GetExecute_Control().SetFlag_ThreadInitialised(1);
                    done_once = false;
                }
            }
            System.Console.WriteLine("Thread Initialised => Thread_Output_Send()");//TestBench
            while (Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().GetExecute_Control().GetFlag_Server_Shell_Initialised() == true)
            {

            }
            System.Console.WriteLine("Thread Started => Thread_Output_Send()");//TestBench
            while (Avril_FSD_ServerAssembly.Framework.GetGameServer().GetExecute().GetExecute_Control().GetFlag_Server_Shell_Initialised() == false)
            {
                Avril_FSD_ServerAssembly.WriteEnable.ServerCallTo_Request_Write_Stack_Server_OutputAction(0);
                while(Avril_FSD_ServerAssembly.WriteEnable.ServerCallTo_Get_Flag_IsStackLoaded_Server_OutputRecieve())
                {
                    Avril_FSD_ServerAssembly.Library.ServerCallTo_Pop_Stack_Output();
                    Avril_FSD_ServerAssembly.Library.ServerCallTo_Flip_OutBufferToWrite();
                    //Valve.Networking.CreateAndSendNewMessage();//todo
                }
                Avril_FSD_ServerAssembly.WriteEnable.ServerCallTo_End_Write_Stack_Server_OutputAction(0);
            }
        */}

        public Avril_FSD_ServerAssembly.IO_ListenRespond_Control GetIO_Control()
        {
            return io_Control;
        }
    }
}
