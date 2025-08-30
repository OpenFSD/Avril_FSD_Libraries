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

void Avril_FSD::Data_Control::Pop_Stack_InputPraises(__int8 concurrentCoreId)
{
    class Avril_FSD::Input* referenceForCore = Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_InputRefferenceOfCore(concurrentCoreId);
    std::vector<class Avril_FSD::Input*>* ptr_inputStack = Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_Stack_InputPraise();
    referenceForCore = ptr_inputStack->at(1);
    ptr_inputStack->erase(ptr_inputStack->begin()+1);
    if (sizeof(ptr_inputStack) < 2)
    {
        SetFlag_InputStackLoaded(false);
    }
    else
    {
        SetFlag_InputStackLoaded(true);
    }
}

void Avril_FSD::Data_Control::Pop_Stack_Output()
{
    class Output* distributeBuffer = Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->GetBuffer_OutputBackDouble();
    std::vector<class Output*>* ptr_outputStack = Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_Stack_OutputPraise();
    distributeBuffer = ptr_outputStack->at(1);
    ptr_outputStack->erase(ptr_outputStack->begin()+1);
    if (sizeof(ptr_outputStack) < 2)
    {
        SetFlag_OutputStackLoaded(false);
    }
    else
    {
        SetFlag_OutputStackLoaded(true);
    }
}

void Avril_FSD::Data_Control::Push_Stack_InputPraises()
{
    std::vector<class Avril_FSD::Input*>* ptr_InputStack = Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_Stack_InputPraise();
    class Avril_FSD::Input* ptr_Buffer_Praise = Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->GetBuffer_InputBackDouble();
    ptr_InputStack->push_back(ptr_InputStack->at(0));
    ptr_InputStack->at(ptr_InputStack->size()) = ptr_Buffer_Praise;
    if (sizeof(ptr_InputStack) < 2)
    {
        SetFlag_InputStackLoaded(false);
    }
    else
    {
        SetFlag_InputStackLoaded(true);
    }
}

void Avril_FSD::Data_Control::Push_Stack_Output(__int8 concurrentCoreId)
{
    std::vector<class Avril_FSD::Output*>* ptr_outputStack = Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_Stack_OutputPraise();
    class Avril_FSD::Output* ptr_referenceForCore = Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrentCoreId);
    ptr_outputStack->push_back(ptr_outputStack->at(0));
    ptr_outputStack->at(ptr_outputStack->size()) = ptr_referenceForCore;
    if (sizeof(ptr_outputStack) < 2)
    {
        SetFlag_OutputStackLoaded(false);
    }
    else
    {
        SetFlag_OutputStackLoaded(true);
    }
}

bool Avril_FSD::Data_Control::GetFlag_InputStackLoaded()
{
    return flag_isLoaded_Stack_InputPraise;
}
bool Avril_FSD::Data_Control::GetFlag_OutputStackLoaded()
{
    return flag_isLoaded_Stack_OutputPraise;
}

bool Avril_FSD::Data_Control::GetFlag_isNewInputDataReady()
{
    return flag_isNewInputDataReady;
}

bool Avril_FSD::Data_Control::GetFlag_isNewOutputDataReady()
{
    return flag_isNewOutputDataReady;
}

void Avril_FSD::Data_Control::SetFlag_isNewInputDataReady(bool value)
{
    flag_isNewInputDataReady = value;
}

void Avril_FSD::Data_Control::SetFlag_isNewOutputDataReady(bool value)
{
    flag_isNewOutputDataReady = value;
}


void Avril_FSD::Data_Control::SetFlag_InputStackLoaded(bool value)
{
    flag_isLoaded_Stack_InputPraise = value;
}
void Avril_FSD::Data_Control::SetFlag_OutputStackLoaded(bool value)
{
    flag_isLoaded_Stack_OutputPraise = value;
}