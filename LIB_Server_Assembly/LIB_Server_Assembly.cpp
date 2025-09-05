// LIB_Server_Assembly.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_Server_Assembly.h"

class Avril_FSD::Framework_Server* _Server_Assembly;
std::array<float, 3> _fowards;
std::array<float, 3> _up;
std::array<float, 3> _right;

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

Avril_FSD::Server_Library::Server_Library()
{

}
// This is an example of an exported function.
void * Avril_FSD::Server_Library::Initialise_Server_Assembly()
{
    _Server_Assembly = new class Avril_FSD::Framework_Server();
    while (_Server_Assembly == NULL) {}
    _Server_Assembly->Initialise_Program(_Server_Assembly);
    return (void*)_Server_Assembly;
}
bool Avril_FSD::Server_Library::Get_Flag_isNewInputDataReady(class Avril_FSD::Framework_Server* obj)
{
    _Flag_isNewInputDataReady = obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_isNewInputDataReady();
    return _Flag_isNewInputDataReady;
}
bool Avril_FSD::Server_Library::Get_flag_isNewOutputDataReady(class Avril_FSD::Framework_Server* obj)
{
    _flag_isNewOutputDataReady = obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_isNewOutputDataReady();
    return _flag_isNewOutputDataReady; 
}
bool Avril_FSD::Server_Library::Get_Flag_IsStackLoaded_Server_InputAction(class Avril_FSD::Framework_Server* obj)
{
    _Flag_IsStackLoaded_Server_InputAction = obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded();
    return _Flag_IsStackLoaded_Server_InputAction; 
}
bool Avril_FSD::Server_Library::Get_Flag_IsStackLoaded_Server_OutputRecieve(class Avril_FSD::Framework_Server* obj)
{
    _Flag_IsStackLoaded_Server_OutputRecieve = obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded();
    return _Flag_IsStackLoaded_Server_OutputRecieve; 
}
bool Avril_FSD::Server_Library::Get_Flag_IsInitialised_Avril_FSD_ServerAssembly(class Avril_FSD::Framework_Server* obj)
{
    _Flag_IsInitialised_Avril_FSD_ServerAssembly = obj->Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised(obj);
    return _Flag_IsInitialised_Avril_FSD_ServerAssembly;
}
void Avril_FSD::Server_Library::Pop_Stack_Output(class Avril_FSD::Framework_Server* obj)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Pop_Stack_Output(obj);
}
void Avril_FSD::Server_Library::Push_Stack_InputPraises(class Avril_FSD::Framework_Server* obj)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Push_Stack_InputPraises(obj);
}

__int8 Avril_FSD::Server_Library::Get_PraiseEventId(class Avril_FSD::Framework_Server* obj)
{
    _PraiseEventId = obj->Get_Server_Assembly()->Get_Data()->GetBuffer_OutputBackDouble()->GetPraiseEventId();
    return _PraiseEventId;
}
void Avril_FSD::Server_Library::Set_PraiseEventId(class Avril_FSD::Framework_Server* obj, __int8 value)
{
    obj->Get_Server_Assembly()->Get_Data()->GetBuffer_InputBackDouble()->Set_in_praiseEventId(value);
}
//
bool Avril_FSD::Server_Library::Get_Praise0_Input_IsPingActive(class Avril_FSD::Framework_Server* obj)
{
    _Praise0_Input_IsPingActive = obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise0_Input()->Get_ping_Active();
    return _Praise0_Input_IsPingActive;
}
void Avril_FSD::Server_Library::Set_Praise0_Input_IsPingActive(class Avril_FSD::Framework_Server* obj, bool value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise0_Input()->Set_ping_Active(value);
}
bool Avril_FSD::Server_Library::Get_Praise0_Output_IsPingActive(class Avril_FSD::Framework_Server* obj)
{
    _Praise0_Output_IsPingActive = obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise0_Output()->Get_ping_Active();
    return _Praise0_Output_IsPingActive;
}
void Avril_FSD::Server_Library::Set_Praise0_Output_IsPingActive(class Avril_FSD::Framework_Server* obj, bool value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise0_Output()->Set_ping_Active(value);
}
//
float Avril_FSD::Server_Library::Get_Praise1_Input_mouseDelta_X(class Avril_FSD::Framework_Server* obj)
{
    _Praise1_Input_mouseDelta_X = obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Get_mouse_delta_X();
    return _Praise1_Input_mouseDelta_X;
}
void Avril_FSD::Server_Library::Set_Praise1_Input_mouseDelta_X(class Avril_FSD::Framework_Server* obj, float value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Set_mouse_delta_X(value);
}
float Avril_FSD::Server_Library::Get_Praise1_Input_mouseDelta_Y(class Avril_FSD::Framework_Server* obj)
{
    _Praise1_Input_mouseDelta_Y = obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Get_mouse_delta_Y();
    return _Praise1_Input_mouseDelta_Y;
}
void Avril_FSD::Server_Library::Set_Praise1_Input_mouseDelta_Y(class Avril_FSD::Framework_Server* obj, float value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Set_mouse_delta_Y(value);
}

std::array<float, 3> Avril_FSD::Server_Library::Get_Praise1_Output_Player_Fowards(class Avril_FSD::Framework_Server* obj)
{
    _Praise1_Output_Player_Fowards = std::array<float, 3> {_fowards.at(0), _fowards.at(1), _fowards.at(2)};
    return _Praise1_Output_Player_Fowards;
}
std::array<float, 3> Avril_FSD::Server_Library::Get_Praise1_Output_Player_Up(class Avril_FSD::Framework_Server* obj)
{
    _Praise1_Output_Player_Up = std::array<float, 3> {_up.at(0), _up.at(1), _up.at(2)};
    return _Praise1_Output_Player_Up;
}
std::array<float, 3> Avril_FSD::Server_Library::Get_Praise1_Output_Player_Right(class Avril_FSD::Framework_Server* obj)
{
    _Praise1_Output_Player_Right = std::array<float, 3> {_right.at(0), _right.at(1), _right.at(2)};
    return _Praise1_Output_Player_Right;
}
void Avril_FSD::Server_Library::Set_Praise1_Output_Player_Fowards(class Avril_FSD::Framework_Server* obj, std::array<float, 3> value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetFowards(value);
}
void Avril_FSD::Server_Library::Set_Praise1_Output_Player_Up(class Avril_FSD::Framework_Server* obj, std::array<float, 3> value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetUp(value);
}
void Avril_FSD::Server_Library::Set_Praise1_Output_Player_Right(class Avril_FSD::Framework_Server* obj, std::array<float, 3> value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetUp(value);
}

