#include "pch.h"

#include <cstddef>
#include <iostream>
class Avril_FSD::Data_Control* ptr_Data_Control = NULL;
class Avril_FSD::GameInstance* ptr_GameInstance = NULL;
//buffers
bool state_InBufferToWrite = true;
bool state_OutBufferToWrite = true;

class Avril_FSD::Input* ptr_EmptyBuffer_Input = NULL;
class Avril_FSD::Output* ptr_EmptyBuffer_Output = NULL;
class Avril_FSD::Input* ptr_Buffer_InputDouble[2] = { NULL, NULL };
class Avril_FSD::Input* ptr_Buffer_InputReference_ForCore[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
class Avril_FSD::Output* ptr_Buffer_OutputDouble[2] = { NULL, NULL };
class Avril_FSD::Output* ptr_Buffer_OutputReference_ForCore[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES

//buffer sub sets
class Avril_FSD::User_I* ptr_User_I = NULL;
class Avril_FSD::User_O* ptr_User_O = NULL;

std::vector<class Avril_FSD::Input*>* ptr_Stack_InputPraise = NULL;
std::vector<class Avril_FSD::Output*>* ptr_Stack_OutputPraise = NULL;

Avril_FSD::Data::Data(__int8 number_Implemented_Cores)
{
    Set_EmptyBuffer_Input(new class Avril_FSD::Input());
    while (Get_New_InputBuffer() == NULL) { }
    Get_New_InputBuffer()->Initialise_Control();

    Set_EmptyBuffer_Output(new class Avril_FSD::Output());
    while (Get_New_OutputBuffer() == NULL) { }
    Get_New_OutputBuffer()->Initialise_Control();

    Set_Buffer_InputDouble(GetState_InputBuffer(), Get_New_InputBuffer());
    Set_Buffer_InputDouble(!GetState_InputBuffer(), Get_New_InputBuffer());
    while (GetBuffer_InputFrontDouble() == NULL) {}
    while (GetBuffer_InputBackDouble() == NULL) {}

    Set_Buffer_OututDouble(GetState_OutputBuffer(), Get_New_OutputBuffer());
    Set_Buffer_OututDouble(!GetState_OutputBuffer(), Get_New_OutputBuffer());
    while (GetBuffer_OutputFrontDouble() == NULL) {}
    while (GetBuffer_OutputBackDouble() == NULL) {}
    
    for (__int8 index = 0; index < number_Implemented_Cores; index++)//Number Of Cores
    {
        Set_Buffer_InputReference_ForCore(index, Get_New_InputBuffer());
        while (Get_InputRefferenceOfCore(index) == NULL) { }
    }
    for (__int8 index = 0; index < number_Implemented_Cores; index++)
    {
        Set_Buffer_OutputReference_ForCore(index, Get_New_OutputBuffer());
        while (Get_OutputRefferenceOfCore(index) == NULL) {}
    }

    Set_Stack_InputPraise(new std::vector<class Avril_FSD::Input*>);
    while (Get_Stack_InputPraise() == NULL) { }
    Get_Stack_InputPraise()->resize(1);
    Get_Stack_InputPraise()->at(0) = Get_New_InputBuffer();

    Set_Stack_OutputPraise(new std::vector<class Avril_FSD::Output*>);
    while (Get_Stack_OutputPraise() == NULL) { }
    Get_Stack_OutputPraise()->resize(1);
    Get_Stack_OutputPraise()->at(0) = Get_New_OutputBuffer();

    delete ptr_EmptyBuffer_Input;
    delete ptr_EmptyBuffer_Output;

    Set_User_I(new User_I());
    while (Get_User_I() == NULL) { }

    Set_User_O(new User_O());
    while (Get_User_O() == NULL) { }
}

Avril_FSD::Data::~Data()
{
    delete ptr_Data_Control;
    delete ptr_GameInstance;
    
    delete ptr_EmptyBuffer_Input;
    delete ptr_EmptyBuffer_Output;
    for (int index = 0; index < 2; index++)
    {
        delete ptr_Buffer_InputDouble[index];
        delete ptr_Buffer_OutputDouble[index];
    }
    for (int index = 0; index < 3; index++)//NUMBER OF CONCURRENT CORES
    {
        delete ptr_Buffer_InputReference_ForCore[index];
        delete ptr_Buffer_OutputReference_ForCore[index];
    }
    delete ptr_User_I;
    delete ptr_User_O;
    delete ptr_Stack_InputPraise;
    delete ptr_Stack_OutputPraise;

}
void Avril_FSD::Data::Initialise_Control()
{
    Set_Data_Control(new class Avril_FSD::Data_Control());
    while (Get_Data_Control() == NULL) { }
}
void Avril_FSD::Data::Initialise_GameInstance()
{
    Set_GameInstance(new class Avril_FSD::GameInstance());
    while (Get_GameInstance() == NULL) { }
}

__int8 Avril_FSD::Data::BoolToInt(bool bufferSide)
{
    __int8 temp = 2;
    if(bufferSide)
    {
        temp = 1;
    }
    else
    {
        temp = 0;
    }
    return temp;
}

void Avril_FSD::Data::Flip_Input_DoubleBuffer()
{
    Set_state_InBufferToWrite(!GetState_InputBuffer());
}
void Avril_FSD::Data::Flip_Output_DoubleBuffer()
{
    Set_state_OutBufferToWrite(!GetState_OutputBuffer());
}
Avril_FSD::Data_Control* Avril_FSD::Data::Get_Data_Control()
{
    return ptr_Data_Control;
}
Avril_FSD::GameInstance* Avril_FSD::Data::Get_GameInstance()
{
    return ptr_GameInstance;
}
Avril_FSD::Input* Avril_FSD::Data::GetBuffer_InputFrontDouble()
{
    return ptr_Buffer_InputDouble[GetState_InputBuffer()];
}
Avril_FSD::Input* Avril_FSD::Data::GetBuffer_InputBackDouble()
{
    return ptr_Buffer_InputDouble[!GetState_OutputBuffer()];
}
Avril_FSD::Input* Avril_FSD::Data::Get_InputRefferenceOfCore(__int8 concurrent_coreId)
{
    return ptr_Buffer_InputReference_ForCore[concurrent_coreId];
}
Avril_FSD::Output* Avril_FSD::Data::GetBuffer_OutputFrontDouble()
{
    return ptr_Buffer_OutputDouble[BoolToInt(GetState_InputBuffer())];
}
Avril_FSD::Output* Avril_FSD::Data::GetBuffer_OutputBackDouble()
{
    return ptr_Buffer_OutputDouble[BoolToInt(GetState_OutputBuffer())];
}
Avril_FSD::Output* Avril_FSD::Data::Get_OutputRefferenceOfCore(__int8 concurrent_coreId)
{
    return ptr_Buffer_OutputReference_ForCore[concurrent_coreId];
}
Avril_FSD::Input* Avril_FSD::Data::Get_New_InputBuffer()
{
    return ptr_EmptyBuffer_Input;
}
Avril_FSD::Output* Avril_FSD::Data::Get_New_OutputBuffer()
{
    return ptr_EmptyBuffer_Output;
}
bool Avril_FSD::Data::GetState_InputBuffer()
{
    return state_InBufferToWrite;
}
bool Avril_FSD::Data::GetState_OutputBuffer()
{
    return state_OutBufferToWrite;
}
std::vector<class Avril_FSD::Input*>* Avril_FSD::Data::Get_Stack_InputPraise()
{
    return ptr_Stack_InputPraise;
}
std::vector<class Avril_FSD::Output*>* Avril_FSD::Data::Get_Stack_OutputPraise()
{
    return ptr_Stack_OutputPraise;
}
Avril_FSD::User_I* Avril_FSD::Data::Get_User_I()
{
    return ptr_User_I;
}
Avril_FSD::User_O* Avril_FSD::Data::Get_User_O()
{
    return ptr_User_O;
}

void Avril_FSD::Data::Set_Data_Control(Data_Control* data_Control)
{
    ptr_Data_Control = data_Control;
}
void Avril_FSD::Data::Set_GameInstance(GameInstance* gameInstance)
{
    ptr_GameInstance = gameInstance;
}
void Avril_FSD::Data::Set_EmptyBuffer_Input(Input* emptyBuffer_Input)
{
    ptr_EmptyBuffer_Input = emptyBuffer_Input;
}
void Avril_FSD::Data::Set_EmptyBuffer_Output(Output* emptyBuffer_Output)
{
    ptr_EmptyBuffer_Output = emptyBuffer_Output;
}
void Avril_FSD::Data::Set_Buffer_InputDouble(bool state, Input* buffer_InputDouble)
{
    ptr_Buffer_InputDouble[BoolToInt(state)] = buffer_InputDouble;
}
void Avril_FSD::Data::Set_Buffer_InputReference_ForCore(__int8 index, Input* buffer_InputReference_ForCore)
{
    ptr_Buffer_InputReference_ForCore[index] = buffer_InputReference_ForCore;
}
void Avril_FSD::Data::Set_Buffer_OututDouble(bool state, Output* buffer_OututDouble)
{
    ptr_Buffer_OutputDouble[BoolToInt(state)] = buffer_OututDouble;
}
void Avril_FSD::Data::Set_Buffer_OutputReference_ForCore(__int8 index, Output* buffer_OutputReference_ForCore)
{
    ptr_Buffer_OutputReference_ForCore[index] = buffer_OutputReference_ForCore;
}
void Avril_FSD::Data::Set_Stack_InputPraise(std::vector<class Input*>* stack_InputPraise)
{
    ptr_Stack_InputPraise = stack_InputPraise;
}
void Avril_FSD::Data::Set_Stack_OutputPraise(std::vector<class Output*>* stack_OutputPraise)
{
    ptr_Stack_OutputPraise = stack_OutputPraise;
}

void Avril_FSD::Data::Set_User_I(User_I* user_Input)
{
    ptr_User_I = user_Input;
}
void Avril_FSD::Data::Set_User_O(User_O* user_Output)
{
    ptr_User_O = user_Output;
}

void Avril_FSD::Data::Set_InputRefferenceOfCore(__int8 concurrent_coreId, Input* value_Input)
{
    ptr_Buffer_InputReference_ForCore[concurrent_coreId] = value_Input;
}

void Avril_FSD::Data::Set_OutputRefferenceOfCore(__int8 concurrent_coreId, Output* value_Output)
{
    ptr_Buffer_OutputReference_ForCore[concurrent_coreId] = value_Output;
}

void Avril_FSD::Data::Set_state_InBufferToWrite(bool value)
{
    state_InBufferToWrite = value;
}
void Avril_FSD::Data::Set_state_OutBufferToWrite(bool value)
{
    state_OutBufferToWrite = value;
}