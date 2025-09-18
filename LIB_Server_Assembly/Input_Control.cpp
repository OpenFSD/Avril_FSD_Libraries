#include "pch.h"

Avril_FSD::Input_Control::Input_Control()
{

}
Avril_FSD::Input_Control::~Input_Control()
{

}

void Avril_FSD::Input_Control::SelectSet_Input_Subset(Avril_FSD::Framework_Server* obj, __int8 praiseEventId)
{
    switch (praiseEventId)
    {
    case 0:
        obj->Get_Server_Assembly()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
            obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise0_Input()
        );
        break;

    case 1:
        obj->Get_Server_Assembly()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
            obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()
        );
        break;

    case 2:
        obj->Get_Server_Assembly()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
            obj->Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise2_Input()
        );
        break;
    }
}