
namespace Avril_FSD_ServerAssembly
{
    public class Output_Instance
    {
        Avril_FSD_ServerAssembly.Output empty_OutputBuffer;
        Avril_FSD_ServerAssembly.Output[] outputDoubleBuffer;
        Avril_FSD_ServerAssembly.Output transmitOutputBuffer;

        public Output_Instance()
        {
            empty_OutputBuffer = new Avril_FSD_ServerAssembly.Output();
            while (empty_OutputBuffer == null) { /* Wait while is created */ }
            empty_OutputBuffer.InitialiseControl();

            outputDoubleBuffer = new Avril_FSD_ServerAssembly.Output[2];
            for (byte index = 0; index < 2; index++)
            {
                outputDoubleBuffer[index] = empty_OutputBuffer;
                while (outputDoubleBuffer == null) { /* Wait while is created */ }
            }

            transmitOutputBuffer = new Avril_FSD_ServerAssembly.Output();
            while (transmitOutputBuffer == null) { /* Wait while is created */ }

        }

        private ushort BoolToInt16(bool value)
        {
            ushort temp = new ushort();
            if (value)
            {
                temp = 1;
            }
            else if (!value)
            {
                temp = 0;
            }
            return temp;
        }

        public Avril_FSD_ServerAssembly.Output GetEmptyOutput()
        {
            return empty_OutputBuffer;
        }
        public Avril_FSD_ServerAssembly.Output GetBuffer_FrontOutputDouble()
        {
            return outputDoubleBuffer[BoolToInt16(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().Get_state_Buffer_OutputPraise_SideToWrite())];
        }
        public Avril_FSD_ServerAssembly.Output GetBuffer_BackOutputDouble()
        {
            return outputDoubleBuffer[BoolToInt16(!Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().Get_state_Buffer_OutputPraise_SideToWrite())];
        }
        public Avril_FSD_ServerAssembly.Output GetTransmitOutputBuffer()
        {
            return transmitOutputBuffer;
        }
        public void SetBuffer_Output(Avril_FSD_ServerAssembly.Output value)
        {
            outputDoubleBuffer[BoolToInt16(!Framework.GetGameServer().GetData().Get_state_Buffer_InputPraise_SideToWrite())] = value;
        }
    }
}
