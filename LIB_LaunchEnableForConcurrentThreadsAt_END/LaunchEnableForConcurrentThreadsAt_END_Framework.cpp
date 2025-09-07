#include "LaunchEnableForConcurrentThreadsAt_END_Framework.h"
#include "pch.h"

#include <cstddef>

class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END* ptr_LaunchConcurrency = NULL;

Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework::LaunchEnableForConcurrentThreadsAt_END_Framework()
{
	Create_LaunchEnableForConcurrentThreadsAt();
}

Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework::~LaunchEnableForConcurrentThreadsAt_END_Framework()
{

}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_END* Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework::Get_LaunchEnableForConcurrentThread()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework::Create_LaunchEnableForConcurrentThreadsAt()
{
	Set_LaunchEnableForConcurrentThreadsAt(new class Avril_FSD::LaunchEnableForConcurrentThreadsAt_END());
	while (Get__LaunchEnableForConcurrentThreadsAt() == NULL) { /* wait untill created */ }
	Get__LaunchEnableForConcurrentThreadsAt()->Initialise_Control();
}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_END* Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework::Get__LaunchEnableForConcurrentThreadsAt()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_END_Framework::Set_LaunchEnableForConcurrentThreadsAt(Avril_FSD::LaunchEnableForConcurrentThreadsAt_END* concurrentQue)
{
	ptr_LaunchConcurrency = concurrentQue;
}