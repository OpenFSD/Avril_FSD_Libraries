// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_EXPORTS
#define LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_API __declspec(dllexport)
#else
#define LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_API __declspec(dllimport)
#endif

// This class is exported from the dll
class LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_API CLIBWriteEnableForThreadsAtServerInputAction {
public:
	CLIBWriteEnableForThreadsAtServerInputAction(void);
	// TODO: add your methods here.
};

extern LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_API int nLIBWriteEnableForThreadsAtServerInputAction;

LIBWRITEENABLEFORTHREADSATSERVERINPUTACTION_API int fnLIBWriteEnableForThreadsAtServerInputAction(void);
