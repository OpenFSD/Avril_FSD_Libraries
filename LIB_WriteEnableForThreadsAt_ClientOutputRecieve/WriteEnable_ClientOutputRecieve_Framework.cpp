#include "pch.h"
#include <cstddef>

class Avril_FSD::WriteEnable_ClientOutputRecieve* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnable_ClientOutputRecieve_Framework::WriteEnable_ClientOutputRecieve_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnable_ClientOutputRecieve());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}
Avril_FSD::WriteEnable_ClientOutputRecieve_Framework::~WriteEnable_ClientOutputRecieve_Framework()
{

}
Avril_FSD::WriteEnable_ClientOutputRecieve* Avril_FSD::WriteEnable_ClientOutputRecieve_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnable_ClientOutputRecieve_Framework::Set_writeEnable(Avril_FSD::WriteEnable_ClientOutputRecieve* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}