#include "pch.h"

namespace Avril_FSD
{

	Concurrent_Control::Concurrent_Control()
	{

	}
	Concurrent_Control::~Concurrent_Control()
	{

	}

	void Concurrent_Control::SelectSet_Algorithm_Subset(class Avril_FSD::Framework_Server* obj, __int8 ptr_praiseEventId, __int8 concurrent_coreId)
	{
		switch (ptr_praiseEventId)
		{
		case 0:
			obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Set_Algorithm_Subset(
				obj->Get_Server_Assembly()->Get_Algorithms()->Get_User_Algorithms()->Get_Praise0_Algorithm()
			);
			break;

		case 1:
			obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Set_Algorithm_Subset(
				obj->Get_Server_Assembly()->Get_Algorithms()->Get_User_Algorithms()->Get_Praise1_Algorithm()
			);
			break;

		case 2:
			obj->Get_Server_Assembly()->Get_Algorithms()->Get_Concurrent(concurrent_coreId)->Set_Algorithm_Subset(
				obj->Get_Server_Assembly()->Get_Algorithms()->Get_User_Algorithms()->Get_Praise2_Algorithm()
			);
			break;
		}
	}
}