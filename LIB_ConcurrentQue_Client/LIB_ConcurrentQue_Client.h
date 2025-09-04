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
		void* Initialise_ConcurrentQue();

		void Request_Wait_Launch(class Avril_FSD::ConcurrentQue_Client_Framework* obj, unsigned char concurrent_CoreId);
		void Thread_End(class Avril_FSD::ConcurrentQue_Client_Framework*, unsigned char concurrent_CoreId);

		__int8 Get_coreId_To_Launch(class Avril_FSD::ConcurrentQue_Client_Framework* obj);
		bool Get_Flag_Active(class Avril_FSD::ConcurrentQue_Client_Framework* obj);
		bool Get_Flag_ConcurrentCoreState(class Avril_FSD::ConcurrentQue_Client_Framework* obj, unsigned char concurrent_CoreId);
		bool Get_Flag_Idle(class Avril_FSD::ConcurrentQue_Client_Framework* obj);
		bool Get_State_LaunchBit(class Avril_FSD::ConcurrentQue_Client_Framework* obj);
		void Set_state_ConcurrentCore(class Avril_FSD::ConcurrentQue_Client_Framework* obj, unsigned char concurrent_CoreId, bool value);

	private:
		static class ConcurrentQue_Client_Framework* Get_ConcurrentQue_Client_Framework();
		static void Set_ConcurrentQue_Client_Framework(class ConcurrentQue_Client_Framework* framework);
	};
}