#include "pch.h"


class Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}
Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework::~WriteEnableForThreadsAt_SERVERINPUTACTION_Framework()
{

}
Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION* Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION_Framework::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_SERVERINPUTACTION* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}