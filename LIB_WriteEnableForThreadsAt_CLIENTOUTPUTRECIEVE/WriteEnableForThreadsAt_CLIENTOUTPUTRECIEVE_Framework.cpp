#include "pch.h"
#include <cstddef>

class Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}
Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework::~WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework()
{

}
Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE* Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE_Framework::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_CLIENTOUTPUTRECIEVE* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}