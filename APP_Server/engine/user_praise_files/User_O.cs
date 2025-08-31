
namespace Avril_FSD_ServerAssembly
{
    public class User_O
    {
        Avril_FSD_ServerAssembly.Praise0_Output praise0_Output;
         Avril_FSD_ServerAssembly.Praise1_Output praise1_Output;

        public User_O()
        {
            praise0_Output = new Avril_FSD_ServerAssembly.Praise0_Output();
            praise1_Output = new Avril_FSD_ServerAssembly.Praise1_Output();
        }

        public Avril_FSD_ServerAssembly.Praise0_Output GetPraise0_Outnput()
        {
            return praise0_Output;
        }

        public Avril_FSD_ServerAssembly.Praise1_Output GetPraise1_Output()
        {
            return praise1_Output;
        }
    }
}
