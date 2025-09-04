#include "pch.h"
#include <cstddef>

class Avril_FSD::WriteEnable_ServerInputAction* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnable_ServerInputAction_Framework::WriteEnable_ServerInputAction_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnable_ServerInputAction());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}
Avril_FSD::WriteEnable_ServerInputAction_Framework::~WriteEnable_ServerInputAction_Framework()
{

}
Avril_FSD::WriteEnable_ServerInputAction* Avril_FSD::WriteEnable_ServerInputAction_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnable_ServerInputAction_Framework::Set_writeEnable(Avril_FSD::WriteEnable_ServerInputAction* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}