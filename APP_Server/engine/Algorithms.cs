
namespace Avril_FSD_ServerAssembly
{
    public class Algorithms
    {
        static private Avril_FSD_ServerAssembly.IO_ListenRespond _io_ListenRespond = null;

        public Algorithms(byte numberOfCores)
        {
            System.Console.WriteLine("Avril_FSD_ServerAssembly: Algorithms");//TEST
        }

        public void Initialise(byte numberOfCores)
        {
            SetIO_listenRespond(new Avril_FSD_ServerAssembly.IO_ListenRespond());
            while (GetIO_ListenRespond() == null) { /* wait untill class constructed */ }
            GetIO_ListenRespond().InitialiseControl();
        }

        public Avril_FSD_ServerAssembly.IO_ListenRespond GetIO_ListenRespond()
        {
            return _io_ListenRespond;
        }
        private void SetIO_listenRespond(Avril_FSD_ServerAssembly.IO_ListenRespond value)
        {
            _io_ListenRespond = value;
        }
    }
}