#pragma once
#ifdef LIBSERVERASSEMBLY_EXPORTS
#define LIBSERVERASSEMBLY_API __declspec(dllexport)
#else
#define LIBSERVERASSEMBLY_API __declspec(dllimport)
#endif
#include <array>
namespace Avril_FSD
{
	class LIBSERVERASSEMBLY_API LIB_ServerLibrary {
	public:
		LIB_ServerLibrary();
		void* Initialise_Server_Assembly();
		static bool Get_Flag_isNewInputDataReady(class Framework_Server* obj);
		static bool Get_flag_isNewOutputDataReady();
		static bool Get_Flag_IsStackLoaded_Server_InputAction();
		static bool Get_Flag_IsStackLoaded_Server_OutputRecieve();
		static bool Get_Flag_IsInitialised_Avril_FSD_ServerAssembly();
		static void Pop_Stack_Output();
		static void Push_Stack_InputPraises();
		//static void Set_Flag_isNewInputDataReady(bool value);
// Praise Event Id
		static __int8 Get_PraiseEventId();
		static void Set_PraiseEventId(__int8 value);
// Praise 0 Data
		static bool Get_Praise0_Input_IsPingActive();
		static void Set_Praise0_Input_IsPingActive(bool value);
		static bool Get_Praise0_Output_IsPingActive();
		static void Set_Praise0_Output_IsPingActive(bool value);
// Praise 1 Data
		static float Get_Praise1_Input_mouseDelta_X();
		static float Get_Praise1_Input_mouseDelta_Y();
		static void Set_Praise1_Input_mouseDelta_X(float value);
		static void Set_Praise1_Input_mouseDelta_Y(float value);
		static std::array<float, 3> Get_Praise1_Output_Player_Fowards();
		static std::array<float, 3> Get_Praise1_Output_Player_Up();
		static std::array<float, 3> Get_Praise1_Output_Player_Right();
		static void Set_Praise1_Output_Player_Fowards(std::array<float, 3> value);
		static void Set_Praise1_Output_Player_Up(std::array<float, 3> value);
		static void Set_Praise1_Output_Player_Right(std::array<float, 3> value);
// Praise 0 Data

// TODO: add your methods here.
	};
}