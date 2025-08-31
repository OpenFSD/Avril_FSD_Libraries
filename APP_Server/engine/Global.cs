
namespace Avril_FSD_ServerAssembly
{
    public class Global
    {
        byte numberOfCores;

        public Global()
        {
            numberOfCores = 2;
        }

        public byte Get_NumCores()
        {
            return numberOfCores;
        }
    }
}