
namespace Avril_FSD_ServerAssembly
{ 
    public class Output_Control
    {
        bool[] isSelected_PraiseEventId = new bool[0];
        int numberOfPraises;

        public Output_Control() 
        {
            numberOfPraises = 2;
            isSelected_PraiseEventId = new bool[numberOfPraises];
        }

        void SelectSetOutputSubset(
            int praiseEventId
        )
        {
            switch (praiseEventId)
            {
                case 0:
                    Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetOutput_Instnace().GetBuffer_BackOutputDouble().SetInputBufferSubSet(
                        Framework.GetGameServer().GetData().GetUserI().GetPraise0_Input()
                    );
                    break;

                case 1:
                    Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetOutput_Instnace().GetBuffer_BackOutputDouble().SetInputBufferSubSet(
                        Framework.GetGameServer().GetData().GetUserI().GetPraise1_Input()
                    );
                    break;
            }
        }
    }
}
