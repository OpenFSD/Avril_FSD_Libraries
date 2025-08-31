using System;

namespace Avril_FSD_ServerAssembly
{
    public class Input
    {
        Avril_FSD_ServerAssembly.Input_Control input_Control;
       // static private Avril_FSD_ServerAssembly player;
        Object praiseInputBuffer_Subset;

        UInt16 praiseEventId;
        

        public Input()
        {
            input_Control = null;

            praiseEventId = new int();
            praiseEventId = 0;

            praiseInputBuffer_Subset = null;

           // player = new Avril_FSD_ServerAssembly();
           // while (player == null) { /* Wait while is created */ }

            System.Console.WriteLine("Avril_FSD_ServerAssembly: Input");
        }

        public void InitialiseControl() 
        {
            input_Control = new Avril_FSD_ServerAssembly.Input_Control();
            while (input_Control == null) { /* Wait while is created */ }
        }

        public Object Get_InputBufferSubset()
        {
            return praiseInputBuffer_Subset;
        }

        public Avril_FSD_ServerAssembly.Input_Control GetInputControl()
        {
            return input_Control;
        }

        //public Avril_FSD_ServerAssembly GetPlayer() 
        //{ 
        //    return player; 
        //}

        public int GetPraiseEventId() 
        {   
            return praiseEventId; 
        }

        public void Set_InputBuffer_SubSet(Object value)
        {
            praiseInputBuffer_Subset = value;
        }

        public void SetPraiseEventId(UInt16 value)
        {
            praiseEventId = value;
        }
    }
}