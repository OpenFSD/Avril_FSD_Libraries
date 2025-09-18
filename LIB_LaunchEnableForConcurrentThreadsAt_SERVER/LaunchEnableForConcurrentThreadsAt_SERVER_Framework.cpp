#include "pch.h"

class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER* ptr_LaunchConcurrency = NULL;

Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework::LaunchEnableForConcurrentThreadsAt_SERVER_Framework()
{
	Create_LaunchEnableForConcurrentThreadsAt();
}

Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework::~LaunchEnableForConcurrentThreadsAt_SERVER_Framework()
{

}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER* Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework::Get_LaunchEnableForConcurrentThread()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework::Create_LaunchEnableForConcurrentThreadsAt()
{
	Set_LaunchEnableForConcurrentThreadsAt(new class Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER());
	while (Get__LaunchEnableForConcurrentThreadsAt() == NULL) { /* wait untill created */ }
	Get__LaunchEnableForConcurrentThreadsAt()->Initialise_Control();
}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER* Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework::Get__LaunchEnableForConcurrentThreadsAt()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER_Framework::Set_LaunchEnableForConcurrentThreadsAt(Avril_FSD::LaunchEnableForConcurrentThreadsAt_SERVER* concurrentQue)
{
	ptr_LaunchConcurrency = concurrentQue;
}