// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_EXPORTS
#define LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API __declspec(dllexport)
#else
#define LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API CLIBLaunchEnableForConcurrentThreadsAtSERVER {
public:
	CLIBLaunchEnableForConcurrentThreadsAtSERVER(void);
	// TODO: add your methods here.
};

extern LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API int nLIBLaunchEnableForConcurrentThreadsAtSERVER;

LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API int fnLIBLaunchEnableForConcurrentThreadsAtSERVER(void);
