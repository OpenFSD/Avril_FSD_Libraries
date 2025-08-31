
namespace Avril_FSD_ServerAssembly
{
    public class Global
    {
        byte numberOfCores;

        public Global()
        {
            Set_NumberOFCores(2);
        }

        public byte Get_NumCores()
        {
            return numberOfCores;
        }

        private void Set_NumberOFCores(byte value)
        {
            numberOfCores = value;
        }
    }
}