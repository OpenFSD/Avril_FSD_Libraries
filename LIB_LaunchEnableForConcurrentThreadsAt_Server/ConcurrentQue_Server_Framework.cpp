#include "ConcurrentQue_Server_Framework.h"
#include "pch.h"

#include <cstddef>

class Avril_FSD::ConcurrentQue_Server* ptr_LaunchConcurrency = NULL;

Avril_FSD::ConcurrentQue_Server_Framework::ConcurrentQue_Server_Framework()
{
	Create_ConcurrentQue();
}

Avril_FSD::ConcurrentQue_Server_Framework::~ConcurrentQue_Server_Framework()
{

}
Avril_FSD::ConcurrentQue_Server* Avril_FSD::ConcurrentQue_Server_Framework::Get_ConcurrentQue()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::ConcurrentQue_Server_Framework::Create_ConcurrentQue()
{
	Set_ConcurrentQue(new class Avril_FSD::ConcurrentQue_Server());
	while (Get_ConcurrentQue() == NULL) { /* wait untill created */ }
	Get_ConcurrentQue()->Initialise_Control();
}
//Avril_FSD::ConcurrentQue_Server* Avril_FSD::ConcurrentQue_Server_Framework::Get__ConcurrentQue()
//{
//	return ptr_LaunchConcurrency;
//}
void Avril_FSD::ConcurrentQue_Server_Framework::Set_ConcurrentQue(Avril_FSD::ConcurrentQue_Server* concurrentQue)
{
	ptr_LaunchConcurrency = concurrentQue;
}