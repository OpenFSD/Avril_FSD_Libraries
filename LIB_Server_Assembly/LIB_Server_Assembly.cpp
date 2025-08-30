// LIB_Server_Assembly.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_Server_Assembly.h"

class Avril_FSD::Framework_Server* ptr_Server_Framework = NULL;

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

void Avril_FSD::LIB_ServerLibrary::Flip_InBufferToWrite()
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Flip_Input_DoubleBuffer();
}
void Avril_FSD::LIB_ServerLibrary::Flip_OutBufferToWrite()
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Flip_Output_DoubleBuffer();
}
bool Avril_FSD::LIB_ServerLibrary::Get_Flag_IsStackLoaded_Server_InputAction()
{
    return ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded();
}
bool Avril_FSD::LIB_ServerLibrary::Get_Flag_IsStackLoaded_Server_OutputRecieve()
{
    return ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded();
}
bool Avril_FSD::LIB_ServerLibrary::GetFlag_Avril_FSD_Initialised()
{
    return ptr_Server_Framework->Get_Server_Assembly()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised();
}
void Avril_FSD::LIB_ServerLibrary::Pop_Stack_Output()
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Pop_Stack_Output();
}
void Avril_FSD::LIB_ServerLibrary::Push_Stack_InputPraises()
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->Get_Data_Control()->Push_Stack_InputPraises();
}
//
__int8 Avril_FSD::LIB_ServerLibrary::Get_PraiseEventId()
{
    return ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->GetBuffer_OutputBackDouble()->GetPraiseEventId();
}
void Avril_FSD::LIB_ServerLibrary::Set_PraiseEventId(__int8 value)
{
    ptr_Server_Framework->Get_Server_Assembly()->Get_Data()->GetBuffer_InputBackDouble()->Set_in_praiseEventId(value);
}
//