#include "pch.h"


class Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}
Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework::~WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework()
{

}
Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION* Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION_Framework::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_CLIENTINPUTACTION* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}