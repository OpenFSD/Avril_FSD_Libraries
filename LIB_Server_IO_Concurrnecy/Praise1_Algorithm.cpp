#include "pch.h"

Avril_FSD::Praise1_Algorithm::Praise1_Algorithm()
{
}

Avril_FSD::Praise1_Algorithm::~Praise1_Algorithm()
{
}

void Avril_FSD::Praise1_Algorithm::Do_Praise(Avril_FSD::Framework_Server* obj, char playerId, Avril_FSD::Praise1_Input* in_SubSet, Avril_FSD::Praise1_Output* out_SubSet)
{
    Avril_FSD::Player* selectedPlayer = obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_player(playerId);
    if (selectedPlayer->Get_isFirstMouseMove())
    {
        std::vector<float> mousePosition = {in_SubSet->Get_mouse_X(), in_SubSet->Get_mouse_Y()};
        selectedPlayer->Set_mouse_Position(mousePosition);
        selectedPlayer->Set_isFirstMouseMove(false);
    }
    else
    {
        switch (selectedPlayer->Get_cameraSelector())
        {
        case false:
            if ((in_SubSet->Get_mouse_X() != (float)(obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_settings()->Get_screenSize_X() / 2))
                || (in_SubSet->Get_mouse_Y() != (float)(obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_settings()->Get_screenSize_Y() / 2)))
            {
                float sensitivity = selectedPlayer->Get_sensitivity();
                float anglePerPixle = obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_settings()->Get_fov() / obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_settings()->Get_screenSize_Y();
                float deltaX = anglePerPixle * (in_SubSet->Get_mouse_X() - (obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_settings()->Get_screenSize_X() / 2));
                float deltaY = anglePerPixle * (in_SubSet->Get_mouse_Y() - (obj->Get_Server_Assembly()->Get_Data()->Get_GameInstance()->Get_settings()->Get_screenSize_Y() / 2));
                selectedPlayer->Get_camera_FP()->Update_Yaw(deltaX);
                selectedPlayer->Get_camera_FP()->Update_Pitch(deltaY);
                selectedPlayer->Get_camera_FP()->UpdateVectors(selectedPlayer->Get_camera_FP()->Get_pitch(), selectedPlayer->Get_camera_FP()->Get_yaw());
                //OpenTK.Input.Mouse.SetPosition((double)(obj.Get_server().Get_data().Get_settings().Get_ScreenSize_X() / 2), (double)(obj.Get_server().Get_data().Get_settings().Get_ScreenSize_Y() / 2));
            }
            break;

        case true:

            break;
        }
    }
    out_SubSet->SetFowards(selectedPlayer->Get_camera_FP()->Get_fowards());//todo cast to vector3
    out_SubSet->SetRight(selectedPlayer->Get_camera_FP()->Get_right());
    out_SubSet->SetUp(selectedPlayer->Get_camera_FP()->Get_up());
    //_lastMouseState = mouseState;
    //Console.WriteLine("TESTBENCH => HandleMouse .. Done");
}