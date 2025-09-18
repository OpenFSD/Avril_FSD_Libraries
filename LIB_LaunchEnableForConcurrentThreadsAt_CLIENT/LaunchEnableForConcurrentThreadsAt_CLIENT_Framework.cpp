#include "pch.h"

class Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT* ptr_LaunchConcurrency = NULL;

Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework()
{
	Create_LaunchEnableForConcurrentThreadsAt();
}

Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework::~LaunchEnableForConcurrentThreadsAt_CLIENT_Framework()
{

}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT* Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework::Get_LaunchEnableForConcurrentThread()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework::Create_LaunchEnableForConcurrentThreadsAt()
{
	Set_LaunchEnableForConcurrentThreadsAt(new class Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT());
	while (Get__LaunchEnableForConcurrentThreadsAt() == NULL) { /* wait untill created */ }
	Get__LaunchEnableForConcurrentThreadsAt()->Initialise_Control();
}
Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT* Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework::Get__LaunchEnableForConcurrentThreadsAt()
{
	return ptr_LaunchConcurrency;
}
void Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT_Framework::Set_LaunchEnableForConcurrentThreadsAt(Avril_FSD::LaunchEnableForConcurrentThreadsAt_CLIENT* concurrentQue)
{
	ptr_LaunchConcurrency = concurrentQue;
}