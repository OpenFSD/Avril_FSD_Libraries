// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_EXPORTS
#define LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_API __declspec(dllexport)
#else
#define LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_API __declspec(dllimport)
#endif

// This class is exported from the dll
class LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_API CLIBWriteEnableForThreadsAtClientOutputRecieve {
public:
	CLIBWriteEnableForThreadsAtClientOutputRecieve(void);
	// TODO: add your methods here.
};

extern LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_API int nLIBWriteEnableForThreadsAtClientOutputRecieve;

LIBWRITEENABLEFORTHREADSATCLIENTOUTPUTRECIEVE_API int fnLIBWriteEnableForThreadsAtClientOutputRecieve(void);
