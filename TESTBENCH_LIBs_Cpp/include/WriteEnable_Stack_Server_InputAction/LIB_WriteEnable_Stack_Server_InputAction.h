// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBWRITEENABLESTACKCLIENTOUTPUTRECIEVE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBWRITEENABLESTACKCLIENTOUTPUTRECIEVE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef LIBWRITEENABLESTACKCLIENTOUTPUTRECIEVE_EXPORTS
#define LIBWRITEENABLESTACKCLIENTOUTPUTRECIEVE_API __declspec(dllexport)
#else
#define LIBWRITEENABLESTACKCLIENTOUTPUTRECIEVE_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	// This class is exported from the dll
	class LIBWRITEENABLESTACKCLIENTOUTPUTRECIEVE_API WriteEnableStackServerInputAction {
	public:
		WriteEnableStackServerInputAction();
		// TODO: add your methods here.
		static class Avril_FSD::WriteEnable_Stack_Server_InputAction_Framework* Initialise_WriteEnableStack_ServerInputAction();
		static void Write_End(unsigned char coreId);
		static void Write_Start(unsigned char coreId);

	private:
		static class Avril_FSD::WriteEnable_Stack_Server_InputAction_Framework* Get_writeEnable();
		static void Set_writeEnable(class Avril_FSD::WriteEnable_Stack_Server_InputAction_Framework* writeEnable);
	};
}