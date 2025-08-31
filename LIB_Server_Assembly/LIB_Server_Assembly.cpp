// LIB_Server_Assembly.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_Server_Assembly.h"

class Avril_FSD::Framework_Server* ptr_Server_Framework = NULL;
std::array<float, 3> _fowards;
std::array<float, 3> _up;
std::array<float, 3> _right;

class Framework_Server* _Server_Assembly;
bool _Flag_isNewInputDataReady;
bool _flag_isNewOutputDataReady;
bool _Flag_IsStackLoaded_Server_InputAction;
bool _Flag_IsStackLoaded_Server_OutputRecieve;
bool _Flag_IsInitialised_Avril_FSD_ServerAssembly;

// Praise Event Id
__int8 _PraiseEventId;

// Praise 0 Data
bool _Praise0_Input_IsPingActive;
bool _Praise0_Output_IsPingActive;

// Praise 1 Data
float _Praise1_Input_mouseDelta_X;
float _Praise1_Input_mouseDelta_Y;
std::array<float, 3> _Praise1_Output_Player_Fowards;
std::array<float, 3> _Praise1_Output_Player_Up;
std::array<float, 3> _Praise1_Output_Player_Right;

Avril_FSD::LIB_ServerLibrary::LIB_ServerLibrary()
{

}

// This is an example of an exported function.
Avril_FSD::Framework_Server* Avril_FSD::LIB_ServerLibrary::Initialise_Server_Assembly()
{
    ptr_Server_Framework = new class Avril_FSD::Framework_Server();
    while (ptr_Server_Framework == NULL) {}
    return ptr_Server_Framework;
}

bool Avril_FSD::LIB_ServerLibrary::Get_Flag_isNewInputDataReady()
{
    _Flag_isNewInputDataReady = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_isNewInputDataReady();
    return _Flag_isNewInputDataReady;
}
bool Avril_FSD::LIB_ServerLibrary::Get_flag_isNewOutputDataReady()
{
    _flag_isNewOutputDataReady = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_isNewOutputDataReady();
    return _flag_isNewOutputDataReady; 
}
bool Avril_FSD::LIB_ServerLibrary::Get_Flag_IsStackLoaded_Server_InputAction()
{
    _Flag_IsStackLoaded_Server_InputAction = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded();
    return _Flag_IsStackLoaded_Server_InputAction; 
}
bool Avril_FSD::LIB_ServerLibrary::Get_Flag_IsStackLoaded_Server_OutputRecieve()
{
    _Flag_IsStackLoaded_Server_OutputRecieve = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded();
    return _Flag_IsStackLoaded_Server_OutputRecieve; 
}
bool Avril_FSD::LIB_ServerLibrary::Get_Flag_IsInitialised_Avril_FSD_ServerAssembly()
{
    _Flag_IsInitialised_Avril_FSD_ServerAssembly = ptr_Server_Framework->Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised();
    return _Flag_IsInitialised_Avril_FSD_ServerAssembly;
}
void Avril_FSD::LIB_ServerLibrary::Pop_Stack_Output()
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Pop_Stack_Output();
}
void Avril_FSD::LIB_ServerLibrary::Push_Stack_InputPraises()
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Push_Stack_InputPraises();
}
//void Avril_FSD::LIB_ServerLibrary::Set_Flag_isNewInputDataReady(bool value)
//{
//    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->SetFlag_isNewInputDataReady(value);
//}
//
__int8 Avril_FSD::LIB_ServerLibrary::Get_PraiseEventId()
{
    _PraiseEventId = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->GetBuffer_OutputBackDouble()->GetPraiseEventId();
    return _PraiseEventId;
}
void Avril_FSD::LIB_ServerLibrary::Set_PraiseEventId(__int8 value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->GetBuffer_InputBackDouble()->Set_in_praiseEventId(value);
}
//
bool Avril_FSD::LIB_ServerLibrary::Get_Praise0_Input_IsPingActive()
{
    _Praise0_Input_IsPingActive = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise0_Input()->Get_ping_Active();
    return _Praise0_Input_IsPingActive;
}
void Avril_FSD::LIB_ServerLibrary::Set_Praise0_Input_IsPingActive(bool value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise0_Input()->Set_ping_Active(value);
}
bool Avril_FSD::LIB_ServerLibrary::Get_Praise0_Output_IsPingActive()
{
    _Praise0_Output_IsPingActive = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise0_Output()->Get_ping_Active();
    return _Praise0_Output_IsPingActive;
}
void Avril_FSD::LIB_ServerLibrary::Set_Praise0_Output_IsPingActive(bool value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise0_Output()->Set_ping_Active(value);
}
//
float Avril_FSD::LIB_ServerLibrary::Get_Praise1_Input_mouseDelta_X()
{
    _Praise1_Input_mouseDelta_X = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Get_mouse_delta_X();
    return _Praise1_Input_mouseDelta_X;
}
void Avril_FSD::LIB_ServerLibrary::Set_Praise1_Input_mouseDelta_X(float value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Set_mouse_delta_X(value);
}
float Avril_FSD::LIB_ServerLibrary::Get_Praise1_Input_mouseDelta_Y()
{
    _Praise1_Input_mouseDelta_Y = ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Get_mouse_delta_Y();
    return _Praise1_Input_mouseDelta_Y;
}
void Avril_FSD::LIB_ServerLibrary::Set_Praise1_Input_mouseDelta_Y(float value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Set_mouse_delta_Y(value);
}

std::array<float, 3> Avril_FSD::LIB_ServerLibrary::Get_Praise1_Output_Player_Fowards()
{
    _Praise1_Output_Player_Fowards = std::array<float, 3> {_fowards.at(0), _fowards.at(1), _fowards.at(2)};
    return _Praise1_Output_Player_Fowards;
}
std::array<float, 3> Avril_FSD::LIB_ServerLibrary::Get_Praise1_Output_Player_Up()
{
    _Praise1_Output_Player_Up = std::array<float, 3> {_up.at(0), _up.at(1), _up.at(2)};
    return _Praise1_Output_Player_Up;
}
std::array<float, 3> Avril_FSD::LIB_ServerLibrary::Get_Praise1_Output_Player_Right()
{
    _Praise1_Output_Player_Right = std::array<float, 3> {_right.at(0), _right.at(1), _right.at(2)};
    return _Praise1_Output_Player_Right;
}
void Avril_FSD::LIB_ServerLibrary::Set_Praise1_Output_Player_Fowards(std::array<float, 3> value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetFowards(value);
}
void Avril_FSD::LIB_ServerLibrary::Set_Praise1_Output_Player_Up(std::array<float, 3> value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetUp(value);
}
void Avril_FSD::LIB_ServerLibrary::Set_Praise1_Output_Player_Right(std::array<float, 3> value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetUp(value);
}