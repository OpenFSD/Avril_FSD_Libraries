// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_EXPORTS
#define LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API __declspec(dllexport)
#else
#define LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API __declspec(dllimport)
#endif

// This class is exported from the dll
class LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API CLIBLaunchEnableForConcurrentThreadsAtClient {
public:
	CLIBLaunchEnableForConcurrentThreadsAtClient(void);
	// TODO: add your methods here.
};

extern LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API int nLIBLaunchEnableForConcurrentThreadsAtClient;

LIBLAUNCHENABLEFORCONCURRENTTHREADSATCLIENT_API int fnLIBLaunchEnableForConcurrentThreadsAtClient(void);
