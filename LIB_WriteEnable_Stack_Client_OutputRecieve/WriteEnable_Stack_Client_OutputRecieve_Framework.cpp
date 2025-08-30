#include "pch.h"

#include <cstddef>

class Avril_FSD::WriteEnable_Stack_Client_OutputRecieve* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework::WriteEnable_Stack_Client_OutputRecieve_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnable_Stack_Client_OutputRecieve());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}

Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework::~WriteEnable_Stack_Client_OutputRecieve_Framework()
{

}

void Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework::Write_End(unsigned char coreId)
{
	Get_writeEnable()->Write_End(coreId);
}

void Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework::Write_Start(unsigned char coreId)
{
	Get_writeEnable()->Write_Start(coreId);
}
Avril_FSD::WriteEnable_Stack_Client_OutputRecieve* Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnable_Stack_Client_OutputRecieve_Framework::Set_writeEnable(Avril_FSD::WriteEnable_Stack_Client_OutputRecieve* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}