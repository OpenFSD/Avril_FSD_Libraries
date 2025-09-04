#include "ConcurrentQue_CLIENT_Framework.h"
#include "pch.h"

#include <cstddef>

class Avril_FSD::ConcurrentQue_CLIENT* ptr_LaunchConcurrency = NULL;

Avril_FSD::ConcurrentQue_CLIENT_Framework::ConcurrentQue_CLIENT_Framework()
{
	Create_ConcurrentQue();
}

Avril_FSD::ConcurrentQue_CLIENT_Framework::~ConcurrentQue_CLIENT_Framework()
{

}
Avril_FSD::ConcurrentQue_CLIENT* Avril_FSD::ConcurrentQue_CLIENT_Framework::Get_ConcurrentQue()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::ConcurrentQue_CLIENT_Framework::Create_ConcurrentQue()
{
	Set_ConcurrentQue(new class Avril_FSD::ConcurrentQue_CLIENT());
	while (Get_ConcurrentQue() == NULL) { /* wait untill created */ }
	Get_ConcurrentQue()->Initialise_Control();
}
//Avril_FSD::ConcurrentQue_CLIENT* Avril_FSD::ConcurrentQue_CLIENT_Framework::Get__ConcurrentQue()
//{
//	return ptr_LaunchConcurrency;
//}
void Avril_FSD::ConcurrentQue_CLIENT_Framework::Set_ConcurrentQue(Avril_FSD::ConcurrentQue_CLIENT* concurrentQue)
{
	ptr_LaunchConcurrency = concurrentQue;
}