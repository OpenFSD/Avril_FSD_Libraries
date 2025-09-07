#ifdef LAUNCHENABLEFORCONCURRENTTHREADSATEND_EXPORTS
#define LAUNCHENABLEFORCONCURRENTTHREADSATEND_API __declspec(dllexport)
#else
#define LAUNCHENABLEFORCONCURRENTTHREADSATEND_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	class LAUNCHENABLEFORCONCURRENTTHREADSATEND_API Library_LaunchEnableForConcurrentThreadsAt_END {
	public:
		Library_LaunchEnableForConcurrentThreadsAt_END();
		static void* Initialise_LaunchEnableForConcurrentThreadsAt();

		static void Request_Wait_Launch(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId);
		static void Thread_End(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework*, unsigned char concurrent_CoreId);

		static __int8 Get_coreId_To_Launch(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj);
		static bool Get_Flag_Active(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj);
		static bool Get_Flag_ConcurrentCoreState(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId);
		static bool Get_Flag_Idle(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj);
		static bool Get_State_LaunchBit(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj);
		static void Set_state_ConcurrentCore(class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework* obj, unsigned char concurrent_CoreId, bool value);

	private:
		static class LaunchEnableForConcurrentThreadsAt_END_Framework* Get_LaunchEnableForConcurrentThreadsAt_END_Framework();
		static void Set_LaunchEnableForConcurrentThreadsAt_END_Framework(class LaunchEnableForConcurrentThreadsAt_END_Framework* framework);
	};
}