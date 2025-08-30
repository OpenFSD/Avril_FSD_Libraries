#include "pch.h"

#include <cstddef>

namespace Avril_FSD
{
	class WriteEnable_Stack_Server_InputAction* ptr_WriteEnable = NULL;

	WriteEnableStack_ServerInputAction_Framework::WriteEnableStack_ServerInputAction_Framework()
	{
		Set_writeEnable(new class Avril_FSD::WriteEnable_Stack_Server_InputAction());
		while (Get_writeEnable() == NULL) { /* wait untill created */ }
		Get_writeEnable()->Initialise_Control();
	}

	WriteEnableStack_ServerInputAction_Framework::~WriteEnableStack_ServerInputAction_Framework()
	{

	}

	void WriteEnableStack_ServerInputAction_Framework::Write_End(unsigned char coreId)
	{
		Get_writeEnable()->Write_End(coreId);
	}

	void WriteEnableStack_ServerInputAction_Framework::Write_Start(unsigned char coreId)
	{
		Get_writeEnable()->Write_Start(coreId);
	}
	Avril_FSD::WriteEnable_Stack_Server_InputAction* WriteEnableStack_ServerInputAction_Framework::Get_writeEnable()
	{
		return ptr_WriteEnable;
	}
	void WriteEnableStack_ServerInputAction_Framework::Set_writeEnable(Avril_FSD::WriteEnable_Stack_Server_InputAction* writeEnable)
	{
		ptr_WriteEnable = writeEnable;
	}
}