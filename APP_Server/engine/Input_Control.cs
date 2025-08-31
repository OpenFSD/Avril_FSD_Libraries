
namespace Avril_FSD_ServerAssembly
{
    public class Input_Control
    {
        bool[] isSelected_PraiseEventId = new bool[0];
        int numberOfPraises;

        public Input_Control()
        {
            numberOfPraises = 2;//move to global
            isSelected_PraiseEventId = new bool[numberOfPraises];
        }
    }
}
