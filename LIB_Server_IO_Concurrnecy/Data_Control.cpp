#include "pch.h"

bool flag_isLoaded_Stack_InputPraise = false;
bool flag_isLoaded_Stack_OutputPraise = false;
bool flag_isNewInputDataReady = false;
bool flag_isNewOutputDataReady = false;

Avril_FSD::Data_Control::Data_Control()
{
    flag_isLoaded_Stack_InputPraise = bool(false);
    flag_isLoaded_Stack_OutputPraise = bool(false);
    flag_isNewInputDataReady = bool(false);
    flag_isNewOutputDataReady = bool(false);
}
Avril_FSD::Data_Control::~Data_Control()
{

}
void Avril_FSD::Data_Control::Pop_Stack_InputPraises(class Avril_FSD::Framework_Server* obj, __int8 concurrentCoreId)
{
    class Avril_FSD::Input* referenceForCore = obj->Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrentCoreId);
    std::vector<class Avril_FSD::Input*>* ptr_inputStack = obj->Get_Server_Assembly()->Get_Data()->Get_Stack_InputPraise();
    referenceForCore = ptr_inputStack->at(1);
    ptr_inputStack->erase(ptr_inputStack->begin() + 1);
    if (sizeof(ptr_inputStack) < 2)
    {
        Set_flag_IsStackLoaded_Server_InputAction(false);
    }
    else
    {
        Set_flag_IsStackLoaded_Server_InputAction(true);
    }
}

void Avril_FSD::Data_Control::Pop_Stack_Output(class Avril_FSD::Framework_Server* obj)
{
    class Output* distributeBuffer = obj->Get_Server_Assembly()->Get_Data()->GetBuffer_OutputBackDouble();
    std::vector<class Output*>* ptr_outputStack = obj->Get_Server_Assembly()->Get_Data()->Get_Stack_OutputPraise();
    distributeBuffer = ptr_outputStack->at(1);
    ptr_outputStack->erase(ptr_outputStack->begin() + 1);
    if (sizeof(ptr_outputStack) < 2)
    {
        Set_flag_IsStackLoaded_Server_OutputRecieve(false);
    }
    else
    {
        Set_flag_IsStackLoaded_Server_OutputRecieve(true);
    }
}
void Avril_FSD::Data_Control::Push_Stack_InputPraises(class Avril_FSD::Framework_Server* obj)
{
    std::vector<class Avril_FSD::Input*>* ptr_InputStack = obj->Get_Server_Assembly()->Get_Data()->Get_Stack_InputPraise();
    class Avril_FSD::Input* ptr_Buffer_Praise = obj->Get_Server_Assembly()->Get_Data()->GetBuffer_InputBackDouble();
    ptr_InputStack->push_back(ptr_InputStack->at(0));
    ptr_InputStack->at(ptr_InputStack->size()) = ptr_Buffer_Praise;
    if (sizeof(ptr_InputStack) < 2)
    {
        Set_flag_IsStackLoaded_Server_InputAction(false);
    }
    else
    {
        Set_flag_IsStackLoaded_Server_InputAction(true);
    }
}

void Avril_FSD::Data_Control::Push_Stack_Output(class Avril_FSD::Framework_Server* obj, __int8 concurrentCoreId)
{
    std::vector<class Avril_FSD::Output*>* ptr_outputStack = obj->Get_Server_Assembly()->Get_Data()->Get_Stack_OutputPraise();
    class Avril_FSD::Output* ptr_referenceForCore = obj->Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrentCoreId);
    ptr_outputStack->push_back(ptr_outputStack->at(0));
    ptr_outputStack->at(ptr_outputStack->size()) = ptr_referenceForCore;
    if (sizeof(ptr_outputStack) < 2)
    {
        Set_flag_IsStackLoaded_Server_OutputRecieve(false);
    }
    else
    {
        Set_flag_IsStackLoaded_Server_OutputRecieve(true);
    }
}

void Avril_FSD::Data_Control::Store_Praise_In_Data_To_GameInstance_Data(Framework_Server* obj, std::vector<class Avril_FSD::Input*>* stack)
{
    Avril_FSD::Input* input = stack->at(1);
    switch (input->GetPraiseEventId())
    {
    case 0:
        break;

    case 1:
        Avril_FSD::Praise1_Input* subset = (Avril_FSD::Praise1_Input*)input->Get_InputBuffer_Subset();
        obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_player(input->Get_playerId())->Set_mouse_Position_X(subset->Get_mouse_X());
        obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_player(input->Get_playerId())->Set_mouse_Position_Y(subset->Get_mouse_Y());
        break;
    }
}

void Avril_FSD::Data_Control::Store_Praise_Out_Data_To_GameInstance_Data(Framework_Server* obj, std::vector<class Avril_FSD::Output*>* stack)
{
    Avril_FSD::Output* output = stack->at(1);
    switch (output->Get_out_praiseEventId())
    {
    case 0:
        break;

    case 1:
        Avril_FSD::Praise1_Output* subset = (Avril_FSD::Praise1_Output*)output->Get_praiseOutputBuffer_Subset();
        obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_player(output->Get_out_playerId())->Set_front(subset->GetFowards());
        obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_player(output->Get_out_playerId())->Set_right(subset->GetRight());
        obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_player(output->Get_out_playerId())->Set_up(subset->GetUp());
        break;
    }
}

bool Avril_FSD::Data_Control::Get_flag_IsStackLoaded_Server_InputAction()
{
    return flag_isLoaded_Stack_InputPraise;
}
bool Avril_FSD::Data_Control::Get_flag_IsStackLoaded_Server_OutputRecieve()
{
    return flag_isLoaded_Stack_OutputPraise;
}

bool Avril_FSD::Data_Control::Get_flag_IsNewInputDataReady()
{
    return flag_isNewInputDataReady;
}

bool Avril_FSD::Data_Control::Get_flag_IsNewOutputDataReady()
{
    return flag_isNewOutputDataReady;
}

void Avril_FSD::Data_Control::Set_flag_IsStackLoaded_Server_InputAction(bool value)
{
    flag_isLoaded_Stack_InputPraise = value;
}
void Avril_FSD::Data_Control::Set_flag_IsStackLoaded_Server_OutputRecieve(bool value)
{
    flag_isLoaded_Stack_OutputPraise = value;
}

void Avril_FSD::Data_Control::Set_flag_IsNewInputDataReady(bool value)
{
    flag_isNewInputDataReady = value;
}

void Avril_FSD::Data_Control::Set_flag_IsNewOutputDataReady(bool value)
{
    flag_isNewOutputDataReady = value;
}
