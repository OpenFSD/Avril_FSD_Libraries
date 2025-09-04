#include "pch.h"
#include <cstddef>

class Avril_FSD::WriteEnable_ServerOutputRecieve* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnable_ServerOutputRecieve_Framework::WriteEnable_ServerOutputRecieve_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnable_ServerOutputRecieve());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}
Avril_FSD::WriteEnable_ServerOutputRecieve_Framework::~WriteEnable_ServerOutputRecieve_Framework()
{

}
Avril_FSD::WriteEnable_ServerOutputRecieve* Avril_FSD::WriteEnable_ServerOutputRecieve_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnable_ServerOutputRecieve_Framework::Set_writeEnable(Avril_FSD::WriteEnable_ServerOutputRecieve* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}