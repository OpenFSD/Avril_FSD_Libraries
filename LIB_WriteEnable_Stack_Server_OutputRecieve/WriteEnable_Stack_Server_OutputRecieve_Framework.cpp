#include "pch.h"

#include <cstddef>

class Avril_FSD::WriteEnableStack_ServerOutputRecieve* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework::WriteEnableStack_ServerOutputRecieve_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnableStack_ServerOutputRecieve());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}

Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework::~WriteEnableStack_ServerOutputRecieve_Framework()
{

}

void Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework::Write_End(unsigned char coreId)
{
	Get_writeEnable()->Write_End(coreId);
}

void Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework::Write_Start(unsigned char coreId)
{
	Get_writeEnable()->Write_Start(coreId);
}
Avril_FSD::WriteEnableStack_ServerOutputRecieve* Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnableStack_ServerOutputRecieve_Framework::Set_writeEnable(Avril_FSD::WriteEnableStack_ServerOutputRecieve* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}