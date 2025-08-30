/// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBCONCURRENTQUESERVER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBCONCURRENTQUESERVER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIBCONCURRENTQUECLIENT_EXPORTS
#define LIBCONCURRENTQUECLIENT_API __declspec(dllexport)
#else
#define LIBCONCURRENTQUECLIENT_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	// This class is exported from the dll
	class LIBCONCURRENTQUECLIENT_API ConcurrentQue_Client {
	public:
		ConcurrentQue_Client();
		// TODO: add your methods here.
		static class ConcurrentQue_Client_Framework* Initialise_ConcurrentQue();

		static void Request_Wait_Launch(unsigned char concurrent_CoreId);
		static void Thread_End(unsigned char concurrent_CoreId);

		static __int8 Get_coreId_To_Launch();
		static bool Get_Flag_Active();
		static bool Get_Flag_ConcurrentCoreState(unsigned char concurrent_CoreId);
		static bool Get_Flag_Idle();
		static bool Get_State_LaunchBit();
		static void SetFlag_ConcurrentCoreState(unsigned char concurrent_CoreId, bool value);

	private:
		static class ConcurrentQue_Client_Framework* Get_ConcurrentQue_Client_Framework();
		static void Set_ConcurrentQue_Client_Framework(class ConcurrentQue_Client_Framework* framework);
	};
}