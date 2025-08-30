#include "pch.h"

#include <cstddef>

bool flag_SystemInitialised = NULL;
bool flag_ThreadInitialised[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
	
static class Execute_Control* ptr_Execute_Control;
static std::thread* ptr_Thread_WithCoreId[4];//NUMBER OF CORES

Avril_FSD::Execute_Control::Execute_Control(__int8 number_Implemented_Cores)
{
	flag_SystemInitialised = bool(true);
	bool flag_ThreadInitialised[4] = { bool(true), bool(true), bool(true), bool(true) };//NUMBER OF CORES
	for (__int8 index = 0; index < number_Implemented_Cores; index++) {
		flag_ThreadInitialised[index] = new bool(true);
	}
}
	
Avril_FSD::Execute_Control::~Execute_Control()
{

}

bool Avril_FSD::Execute_Control::GetFlag_SystemInitialised()
{
	flag_SystemInitialised = false;
	for (int index = 0; index < Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Global()->Get_NumCores(); index++)
	{
		if (flag_ThreadInitialised[index] == true)
		{
			flag_SystemInitialised = true;
		}
	}
	return flag_SystemInitialised;
}

bool Avril_FSD::Execute_Control::GetFlag_ThreadInitialised(__int8 coreId)
{
	return flag_ThreadInitialised[coreId];
}

void Avril_FSD::Execute_Control::SetConditionCodeOfThisThreadedCore(__int8 coreId)
{
	//Todo
	SetFlag_ThreadInitialised(coreId);
}

void Avril_FSD::Execute_Control::SetFlag_ThreadInitialised(__int8 coreId)
{
	flag_ThreadInitialised[coreId] = false;
}