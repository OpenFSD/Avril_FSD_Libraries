#include "ConcurrentQue_Server_Framework.h"
#include "pch.h"

#include <cstddef>

class Avril_FSD::ConcurrentQue_Server_LaunchConcurrency* ptr_LaunchConcurrency = NULL;

Avril_FSD::ConcurrentQue_Server_Framework::ConcurrentQue_Server_Framework()
{
	Create_ConcurrentQue();
}

Avril_FSD::ConcurrentQue_Server_Framework::~ConcurrentQue_Server_Framework()
{

}

void Avril_FSD::ConcurrentQue_Server_Framework::Request_Wait_Launch(unsigned char concurrent_CoreId)
{
	Get_ConcurrentQue()->Thread_Start(concurrent_CoreId);
}
void Avril_FSD::ConcurrentQue_Server_Framework::Thread_End(unsigned char concurrent_CoreId)
{
	Get_ConcurrentQue()->Thread_End(concurrent_CoreId);
}

unsigned char Avril_FSD::ConcurrentQue_Server_Framework::Get_coreId_To_Launch()
{
	return Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch();
}
bool Avril_FSD::ConcurrentQue_Server_Framework::Get_Flag_Active()
{
	return Get_ConcurrentQue()->Get_LaunchConcurrency_Global()->GetConst_Core_ACTIVE();
}
bool Avril_FSD::ConcurrentQue_Server_Framework::Get_Flag_ConcurrentCoreState(unsigned char concurrent_CoreId)
{
	return Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Get_State_ConcurrentCore(concurrent_CoreId);
}
bool Avril_FSD::ConcurrentQue_Server_Framework::Get_Flag_Idle()
{
	return Get_ConcurrentQue()->Get_LaunchConcurrency_Global()->GetConst_Core_IDLE();
}
bool Avril_FSD::ConcurrentQue_Server_Framework::Get_State_LaunchBit()
{
	return Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Get_State_ConcurrentCore(0);
}
void Avril_FSD::ConcurrentQue_Server_Framework::SetFlag_ConcurrentCoreState(unsigned char concurrent_CoreId, bool value)
{
	Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->SetFlag_ConcurrentCoreState(concurrent_CoreId, value);
}
void Avril_FSD::ConcurrentQue_Server_Framework::Create_ConcurrentQue()
{
	Set_ConcurrentQue(new class Avril_FSD::ConcurrentQue_Server_LaunchConcurrency());
	while (Get_ConcurrentQue() == NULL) { /* wait untill created */ }
	Get_ConcurrentQue()->Initialise_Control();
}
Avril_FSD::ConcurrentQue_Server_LaunchConcurrency* Avril_FSD::ConcurrentQue_Server_Framework::Get_ConcurrentQue()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::ConcurrentQue_Server_Framework::Set_ConcurrentQue(Avril_FSD::ConcurrentQue_Server_LaunchConcurrency* concurrentQue)
{
	ptr_LaunchConcurrency = concurrentQue;
}