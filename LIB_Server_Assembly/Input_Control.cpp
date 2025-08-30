#include "pch.h"

#include <cstddef>

Avril_FSD::Input_Control::Input_Control()
{

}
Avril_FSD::Input_Control::~Input_Control()
{

}

void Avril_FSD::Input_Control::SelectSet_Input_Subset(__int8 praiseEventId)
{
    switch (praiseEventId)
    {
    case 0:
        Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
            Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise0_Input()
        );
        break;

    case 1:
        Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
            Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise1_Input()
        );
        break;

    case 2:
        Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
            Avril_FSD::Framework_Server::Get_Server_Assembly()->Get_Data()->Get_User_I()->Get_Praise2_Input()
        );
        break;
    }
}