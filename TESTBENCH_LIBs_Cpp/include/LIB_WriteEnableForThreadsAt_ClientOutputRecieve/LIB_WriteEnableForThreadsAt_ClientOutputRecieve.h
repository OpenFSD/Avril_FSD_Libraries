#ifdef LIBWRITEENABLEClientOutputRecieve_EXPORTS
#define LIBWRITEENABLEATClientOutputRecieve_API __declspec(dllexport)
#else
#define LIBWRITEENABLEATClientOutputRecieve_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	class LIBWRITEENABLEATClientOutputRecieve_API WriteEnableForThreadsAt_ClientOutputRecieve_Library {
	public:
		WriteEnableForThreadsAt_ClientOutputRecieve_Library();
		static void* Initialise_WriteEnable();
		void Write_End(class WriteEnable_ClientOutputRecieve_Framework* obj, unsigned char coreId);
		void Write_Start(class WriteEnable_ClientOutputRecieve_Framework* obj, unsigned char coreId);

	private:
		static class WriteEnable_ClientOutputRecieve_Framework* Get_Framework_WriteEnable();
		static void Set_writeEnable(class Avril_FSD::WriteEnable_ClientOutputRecieve_Framework* writeEnable);
	};
}