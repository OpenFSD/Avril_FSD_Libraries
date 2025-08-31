
namespace Avril_FSD_ServerAssembly
{
    public class User_I
    {
        Avril_FSD_ServerAssembly.Praise0_Input praise0_Input;
        Avril_FSD_ServerAssembly.Praise1_Input praise1_Input;

        public User_I() 
        {
            praise0_Input = new Avril_FSD_ServerAssembly.Praise0_Input();
            praise1_Input = new Avril_FSD_ServerAssembly.Praise1_Input();
        }

        public Avril_FSD_ServerAssembly.Praise0_Input GetPraise0_Input()
        {
            return praise0_Input;
        }

        public Avril_FSD_ServerAssembly.Praise1_Input GetPraise1_Input()
        {
            return praise1_Input;
        }
    }
}
