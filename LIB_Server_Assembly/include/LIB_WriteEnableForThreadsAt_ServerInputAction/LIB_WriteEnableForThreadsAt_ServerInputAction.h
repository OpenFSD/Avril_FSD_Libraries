#ifdef LIBWRITEENABLEServerInputAction_EXPORTS
#define LIBWRITEENABLEATServerInputAction_API __declspec(dllexport)
#else
#define LIBWRITEENABLEATServerInputAction_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	class LIBWRITEENABLEATServerInputAction_API WriteEnableForThreadsAt_ServerInputAction_Library {
	public:
		WriteEnableForThreadsAt_ServerInputAction_Library();
		static void* Initialise_WriteEnable();
		void Write_End(class WriteEnable_ServerInputAction_Framework* obj, unsigned char coreId);
		void Write_Start(class WriteEnable_ServerInputAction_Framework* obj, unsigned char coreId);

	private:
		static class WriteEnable_ServerInputAction_Framework* Get_Framework_WriteEnable();
		static void Set_writeEnable(class Avril_FSD::WriteEnable_ServerInputAction_Framework* writeEnable);
	};
}