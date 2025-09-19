// LIB_Server_IO_Concurrnecy.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_Server_IO_Concurrnecy.h"

class Avril_FSD::Framework_Server* _Server_Assembly;

bool _flag_isNewInputDataReady;
bool _flag_isNewOutputDataReady;
bool _flag_IsStackLoaded_Server_InputAction;
bool _flag_IsStackLoaded_Server_OutputRecieve;
bool _flag_IsInitialised_Avril_FSD_ServerAssembly;

// Praise Event Id
__int8 _PraiseEventId;

// Praise 0 Data
bool _Praise0_Input_IsPingActive;
bool _Praise0_Output_IsPingActive;

// Praise 1 Data
float _Praise1_Input_mouseDelta_X;
float _Praise1_Input_mouseDelta_Y;
Eigen::Vector3d _praise1_Output_Player_Camera_Fowards;
Eigen::Vector3d _praise1_Output_Player_Camera_Up;
Eigen::Vector3d _praise1_Output_Player_Camera_Right;

// This is an example of an exported variable
LIBSERVERIOCONCURRNECY_API int nLIBServerIOConcurrnecy=0;

// This is an example of an exported function.
LIBSERVERIOCONCURRNECY_API int fnLIBServerIOConcurrnecy(void)
{
    return 0;
}
void* Avril_FSD::CLIBServerIOConcurrnecy::Initialise_Server_Concurrency()
{
    _Server_Assembly = new class Avril_FSD::Framework_Server();
    while (_Server_Assembly == NULL) {}
    _Server_Assembly->Initialise_Program(_Server_Assembly);
    return (void*)_Server_Assembly;
}

bool Avril_FSD::CLIBServerIOConcurrnecy::Get_flag_isNewInputDataReady(Avril_FSD::Framework_Server* obj)
{
    _flag_isNewInputDataReady = obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Get_flag_IsNewInputDataReady();
    return _flag_isNewInputDataReady; 
}

bool Avril_FSD::CLIBServerIOConcurrnecy::Get_flag_isNewOutputDataReady(Avril_FSD::Framework_Server* obj)
{
    _flag_isNewOutputDataReady = obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Get_flag_IsNewOutputDataReady();
    return _flag_isNewOutputDataReady;
}

bool Avril_FSD::CLIBServerIOConcurrnecy::Get_flag_IsStackLoaded_Server_InputAction(class Avril_FSD::Framework_Server* obj)
{
    _flag_IsStackLoaded_Server_InputAction = obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Get_flag_IsStackLoaded_Server_InputAction();
    return _flag_IsStackLoaded_Server_InputAction;
}
bool Avril_FSD::CLIBServerIOConcurrnecy::Get_flag_IsStackLoaded_Server_OutputRecieve(class Avril_FSD::Framework_Server* obj)
{
    _flag_IsStackLoaded_Server_OutputRecieve = obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Get_flag_IsStackLoaded_Server_OutputRecieve();
    return _flag_IsStackLoaded_Server_OutputRecieve;
}
bool Avril_FSD::CLIBServerIOConcurrnecy::Get_flag_IsInitialised_Avril_FSD_ServerConcurrency(class Avril_FSD::Framework_Server* obj)
{
    _flag_IsInitialised_Avril_FSD_ServerAssembly = obj->Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised(obj);
    return _flag_IsInitialised_Avril_FSD_ServerAssembly;
}
void Avril_FSD::CLIBServerIOConcurrnecy::Pop_Stack_Output(class Avril_FSD::Framework_Server* obj)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Pop_Stack_Output(obj);
}
void Avril_FSD::CLIBServerIOConcurrnecy::Push_Stack_InputPraises(class Avril_FSD::Framework_Server* obj)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Push_Stack_InputPraises(obj);
}

__int8 Avril_FSD::CLIBServerIOConcurrnecy::Get_PraiseEventId(class Avril_FSD::Framework_Server* obj)
{
    _PraiseEventId = obj->Get_Server_Assembly()->Get_Data()->GetBuffer_OutputBackDouble()->Get_out_praiseEventId();
    return _PraiseEventId;
}
void Avril_FSD::CLIBServerIOConcurrnecy::Set_PraiseEventId(class Avril_FSD::Framework_Server* obj, __int8 value)
{
    obj->Get_Server_Assembly()->Get_Data()->GetBuffer_InputBackDouble()->Set_in_praiseEventId(value);
}
//
bool Avril_FSD::CLIBServerIOConcurrnecy::Get_Praise0_Input_IsPingActive(class Avril_FSD::Framework_Server* obj)
{
    _Praise0_Input_IsPingActive = obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise0_Input()->Get_ping_Active();
    return _Praise0_Input_IsPingActive;
}
void Avril_FSD::CLIBServerIOConcurrnecy::Set_Praise0_Input_IsPingActive(class Avril_FSD::Framework_Server* obj, bool value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise0_Input()->Set_ping_Active(value);
}
bool Avril_FSD::CLIBServerIOConcurrnecy::Get_Praise0_Output_IsPingActive(class Avril_FSD::Framework_Server* obj)
{
    _Praise0_Output_IsPingActive = obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise0_Output()->Get_ping_Active();
    return _Praise0_Output_IsPingActive;
}
void Avril_FSD::CLIBServerIOConcurrnecy::Set_Praise0_Output_IsPingActive(class Avril_FSD::Framework_Server* obj, bool value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise0_Output()->Set_ping_Active(value);
}
//
float Avril_FSD::CLIBServerIOConcurrnecy::Get_Praise1_Input_mouseDelta_X(class Avril_FSD::Framework_Server* obj)
{
    _Praise1_Input_mouseDelta_X = obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Get_mouse_X();
    return _Praise1_Input_mouseDelta_X;
}
void Avril_FSD::CLIBServerIOConcurrnecy::Set_Praise1_Input_mouseDelta_X(class Avril_FSD::Framework_Server* obj, float value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Set_mouse_X(value);
}
float Avril_FSD::CLIBServerIOConcurrnecy::Get_Praise1_Input_mouseDelta_Y(class Avril_FSD::Framework_Server* obj)
{
    _Praise1_Input_mouseDelta_Y = obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Get_mouse_Y();
    return _Praise1_Input_mouseDelta_Y;
}
void Avril_FSD::CLIBServerIOConcurrnecy::Set_Praise1_Input_mouseDelta_Y(class Avril_FSD::Framework_Server* obj, float value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()->Set_mouse_Y(value);
}

Eigen::Vector3d Avril_FSD::CLIBServerIOConcurrnecy::Get_Praise1_Output_Player_Fowards(class Avril_FSD::Framework_Server* obj)
{
    Avril_FSD::Praise1_Output* outputSebset = (Avril_FSD::Praise1_Output*)obj->Get_Server_Assembly()->Get_Data()->GetBuffer_OutputFrontDouble()->Get_praiseOutputBuffer_Subset();
    _praise1_Output_Player_Camera_Fowards = outputSebset->GetFowards();
    return _praise1_Output_Player_Camera_Fowards;
}
Eigen::Vector3d Avril_FSD::CLIBServerIOConcurrnecy::Get_Praise1_Output_Player_Up(class Avril_FSD::Framework_Server* obj)
{
    Avril_FSD::Praise1_Output* outputSebset = (Avril_FSD::Praise1_Output*)obj->Get_Server_Assembly()->Get_Data()->GetBuffer_OutputFrontDouble()->Get_praiseOutputBuffer_Subset();
    _praise1_Output_Player_Camera_Up = outputSebset->GetUp();
    return _praise1_Output_Player_Camera_Up;
}
Eigen::Vector3d Avril_FSD::CLIBServerIOConcurrnecy::Get_Praise1_Output_Player_Right(class Avril_FSD::Framework_Server* obj)
{
    Avril_FSD::Praise1_Output* outputSebset = (Avril_FSD::Praise1_Output*)obj->Get_Server_Assembly()->Get_Data()->GetBuffer_OutputFrontDouble()->Get_praiseOutputBuffer_Subset();
    _praise1_Output_Player_Camera_Right = outputSebset->GetRight();
    return _praise1_Output_Player_Camera_Right;
}
void Avril_FSD::CLIBServerIOConcurrnecy::Set_Praise1_Output_Player_Fowards(class Avril_FSD::Framework_Server* obj, Eigen::Vector3d value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetFowards(value);
}
void Avril_FSD::CLIBServerIOConcurrnecy::Set_Praise1_Output_Player_Up(class Avril_FSD::Framework_Server* obj, Eigen::Vector3d value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetUp(value);
}
void Avril_FSD::CLIBServerIOConcurrnecy::Set_Praise1_Output_Player_Right(class Avril_FSD::Framework_Server* obj, Eigen::Vector3d value)
{
    obj->Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()->SetUp(value);
}


// This is the constructor of a class that has been exported.
Avril_FSD::CLIBServerIOConcurrnecy::CLIBServerIOConcurrnecy()
{
    return;
}
