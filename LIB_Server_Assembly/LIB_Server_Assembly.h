#pragma once
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBSERVERASSEMBLY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBSERVERASSEMBLY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIBSERVERASSEMBLY_EXPORTS
#define LIBSERVERASSEMBLY_API __declspec(dllexport)
#else
#define LIBSERVERASSEMBLY_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	class LIBSERVERASSEMBLY_API LIB_ServerLibrary {
	public:
		LIB_ServerLibrary();
		// TODO: add your methods here.
		static class Framework_Server* Initialise_Server_Assembly();

		static void Flip_InBufferToWrite();
		static void Flip_OutBufferToWrite();
		static bool Get_Flag_IsStackLoaded_Server_InputAction();
		static bool Get_Flag_IsStackLoaded_Server_OutputRecieve();
		static bool GetFlag_Avril_FSD_Initialised();
		static void Pop_Stack_Output();
		static void Push_Stack_InputPraises();
		//
		static __int8 Get_PraiseEventId();
		static void Set_PraiseEventId(__int8 value);

	};
}