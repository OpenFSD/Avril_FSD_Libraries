#pragma once

namespace Avril_FSD
{
    class Player
    {
    public:
        Player();
        virtual ~Player();
		class FirstPersonCamera* Get_camera_FP();
		bool Get_isFirstMove();
		bool Get_isFirstMouseMove();
		bool Get_cameraSelector();
		float Get_cameraSpeed();
		float Get_sensitivity();
		std::vector<float> Get_player_Position();
		std::vector<float> Get_Front();
		std::vector<float> Get_Right();
		std::vector<float> Get_Up();
		std::vector<float> Get_mouse_Position();

		void Set_camera_FP(FirstPersonCamera* camera);
		void Set_isFirstMove(bool value);
		void Set_isFirstMouseMove(bool value);
		void Set_cameraSpeed(float cameraSpeed);
		void Set_sensitivity(float sensitivity);
		void Set_player_Position(std::vector<float> position);
		void Set_front(std::vector<float> front);
		void Set_right(std::vector<float> right);
		void Set_up(std::vector<float> up);
		void Set_mouse_Position(std::vector<float> mousePosition);
    };
}