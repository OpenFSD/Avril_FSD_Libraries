
using System;

namespace Avril_FSD_ServerAssembly
{
    public class Input_Instance
    {
        static private Avril_FSD_ServerAssembly.Input_Instance_Control inputInstance_Control;
        static private Avril_FSD_ServerAssembly.Input empty_InputBuffer;
        static private Avril_FSD_ServerAssembly.Input[] inputDoubleBuffer;
        static private Avril_FSD_ServerAssembly.Input transmitInputBuffer;

        public Input_Instance()
        {
            inputInstance_Control = new Avril_FSD_ServerAssembly.Input_Instance_Control();
            while (inputInstance_Control == null) { /* Wait while is created */ }

            empty_InputBuffer = new Avril_FSD_ServerAssembly.Input();
            while (empty_InputBuffer == null) { /* Wait while is created */ }
            empty_InputBuffer.InitialiseControl();

            inputDoubleBuffer = new Avril_FSD_ServerAssembly.Input[2];
            for (byte index = 0; index < 2; index++)
            {
                inputDoubleBuffer[index] = empty_InputBuffer;
                while (inputDoubleBuffer[index] == null) { /* Wait while is created */ }
            }

            transmitInputBuffer = new Avril_FSD_ServerAssembly.Input();
            while (transmitInputBuffer == null) { /* Wait while is created */ }
        }

        private UInt16 BoolToInt16(bool value)
        {
            UInt16 temp = new UInt16();
            if (value)
            {
                temp = (UInt16)1;
            }
            else if (!value)
            {
                temp = (UInt16)0;
            }
            return temp;
        }

        public Avril_FSD_ServerAssembly.Input GetBuffer_Front_InputDouble()
        {
            return inputDoubleBuffer[BoolToInt16(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().Get_state_Buffer_InputPraise_SideToWrite())];
        }
        public Avril_FSD_ServerAssembly.Input GetBuffer_Back_InputDouble()
        {
            return inputDoubleBuffer[BoolToInt16(!Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().Get_state_Buffer_InputPraise_SideToWrite())];
        }

        public Avril_FSD_ServerAssembly.Input GetEmptyInput()
        {
            return empty_InputBuffer;
        }

        public Avril_FSD_ServerAssembly.Input_Instance_Control GetInputInstance_Control()
        {
            return inputInstance_Control;
        }

        public Avril_FSD_ServerAssembly.Input Get_Transmit_InputBuffer()
        {
            return transmitInputBuffer;
        }

        public void SetBuffer_Input(Avril_FSD_ServerAssembly.Input value)
        {
            inputDoubleBuffer[BoolToInt16(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().Get_state_Buffer_InputPraise_SideToWrite())] = value;
        }
    }
}
