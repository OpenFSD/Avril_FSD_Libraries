#include "pch.h"
#include <cstddef>

class Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}
Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework::~WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework()
{

}
Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE* Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework::Set_writeEnable(Avril_FSD::WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}