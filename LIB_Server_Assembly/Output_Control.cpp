#include "pch.h"

Avril_FSD::Output_Control::Output_Control()
{

}
Avril_FSD::Output_Control::~Output_Control()
{

}

void Avril_FSD::Output_Control::SelectSet_Output_Subset(__int8 ptr_praiseEventId, __int8 concurrent_coreId)
{
	switch (ptr_praiseEventId)
	{
	case 0:
		Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Set_OutputBuffer_Subset(
			Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise0_Output()
		);
		break;

	case 1:
		Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Set_OutputBuffer_Subset(
			Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise1_Output()
		);
		break;

	case 2:
		Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Set_OutputBuffer_Subset(
			Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_User_O()->Get_Praise2_Output()
		);
		break;
	}
}