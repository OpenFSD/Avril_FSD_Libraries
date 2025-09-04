#ifdef LIBWRITEENABLEServerOutputRecieve_EXPORTS
#define LIBWRITEENABLEATServerOutputRecieve_API __declspec(dllexport)
#else
#define LIBWRITEENABLEATServerOutputRecieve_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	class LIBWRITEENABLEATServerOutputRecieve_API WriteEnableForThreadsAt_ServerOutputRecieve_Library {
	public:
		WriteEnableForThreadsAt_ServerOutputRecieve_Library();
		static void* Initialise_WriteEnable();
		void Write_End(class WriteEnable_ServerOutputRecieve_Framework* obj, unsigned char coreId);
		void Write_Start(class WriteEnable_ServerOutputRecieve_Framework* obj, unsigned char coreId);

	private:
		static class WriteEnable_ServerOutputRecieve_Framework* Get_Framework_WriteEnable();
		static void Set_writeEnable(class Avril_FSD::WriteEnable_ServerOutputRecieve_Framework* writeEnable);
	};
}