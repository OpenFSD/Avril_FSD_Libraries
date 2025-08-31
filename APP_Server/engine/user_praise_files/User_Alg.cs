
namespace Avril_FSD_ServerAssembly
{
    public class User_Alg
    {
        Avril_FSD_ServerAssembly.Praise0_Algorithm praise0_Algorithm = null;
        Avril_FSD_ServerAssembly.Praise1_Algorithm praise1_Algorithm = null;

        public User_Alg() 
        {
            praise0_Algorithm = new Avril_FSD_ServerAssembly.Praise0_Algorithm();
            while (praise0_Algorithm == null) { /* Wait while is created */ }

            praise1_Algorithm = new Avril_FSD_ServerAssembly.Praise1_Algorithm();
            while (praise1_Algorithm == null) { /* Wait while is created */ }
        }

        public Avril_FSD_ServerAssembly.Praise0_Algorithm GetPraise0_Algorithm()
        {
            return praise0_Algorithm;
        }
    }
}
