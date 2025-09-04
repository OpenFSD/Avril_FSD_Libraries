#ifdef LAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_EXPORTS
#define LAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API __declspec(dllexport)
#else
#define LAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	class LAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API ConcurrentQue_CLIENT_Library {
	public:
		ConcurrentQue_CLIENT_Library();
		static void* Initialise_ConcurrentQue();

		static void Request_Wait_Launch(class Avril_FSD::ConcurrentQue_CLIENT_Framework* obj, unsigned char concurrent_CoreId);
		static void Thread_End(class Avril_FSD::ConcurrentQue_CLIENT_Framework*, unsigned char concurrent_CoreId);

		static __int8 Get_coreId_To_Launch(class Avril_FSD::ConcurrentQue_CLIENT_Framework* obj);
		static bool Get_Flag_Active(class Avril_FSD::ConcurrentQue_CLIENT_Framework* obj);
		static bool Get_Flag_ConcurrentCoreState(class Avril_FSD::ConcurrentQue_CLIENT_Framework* obj, unsigned char concurrent_CoreId);
		static bool Get_Flag_Idle(class Avril_FSD::ConcurrentQue_CLIENT_Framework* obj);
		static bool Get_State_LaunchBit(class Avril_FSD::ConcurrentQue_CLIENT_Framework* obj);
		static void Set_state_ConcurrentCore(class Avril_FSD::ConcurrentQue_CLIENT_Framework* obj, unsigned char concurrent_CoreId, bool value);

	private:
		static class ConcurrentQue_CLIENT_Framework* Get_ConcurrentQue_CLIENT_Framework();
		static void Set_ConcurrentQue_CLIENT_Framework(class ConcurrentQue_CLIENT_Framework* framework);
	};
}