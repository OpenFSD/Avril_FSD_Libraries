#include "ConcurrentQue_Client_Framework.h"
#include "pch.h"

#include <cstddef>

class Avril_FSD::ConcurrentQue_Client_LaunchConcurrency* ptr_LaunchConcurrency = NULL;

Avril_FSD::ConcurrentQue_Client_Framework::ConcurrentQue_Client_Framework()
{
	Create_ConcurrentQue();
}

Avril_FSD::ConcurrentQue_Client_Framework::~ConcurrentQue_Client_Framework()
{

}

void Avril_FSD::ConcurrentQue_Client_Framework::Request_Wait_Launch(unsigned char concurrent_CoreId)
{
	Get_ConcurrentQue()->Thread_Start(concurrent_CoreId);
}
void Avril_FSD::ConcurrentQue_Client_Framework::Thread_End(unsigned char concurrent_CoreId)
{
	Get_ConcurrentQue()->Thread_End(concurrent_CoreId);
}

void Avril_FSD::ConcurrentQue_Client_Framework::Create_ConcurrentQue()
{
	Set_ConcurrentQue(new class Avril_FSD::ConcurrentQue_Client_LaunchConcurrency());
	while (Get_ConcurrentQue() == NULL) { /* wait untill created */ }
	Get_ConcurrentQue()->Initialise_Control();
}
Avril_FSD::ConcurrentQue_Client_LaunchConcurrency* Avril_FSD::ConcurrentQue_Client_Framework::Get_ConcurrentQue()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::ConcurrentQue_Client_Framework::Set_ConcurrentQue(Avril_FSD::ConcurrentQue_Client_LaunchConcurrency* concurrentQue)
{
	ptr_LaunchConcurrency = concurrentQue;
}