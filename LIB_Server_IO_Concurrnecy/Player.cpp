#include "pch.h"

class Avril_FSD::FirstPersonCamera* _camera_FP;

bool _isFirstMove;
bool _isFirstMouseMove;
bool _cameraSelector;
float _cameraSpeed;
float _sensitivity;
std::vector<float> _player_Position;
std::vector<float> _player_mouse_Position;
Eigen::Vector3d _player_front;
Eigen::Vector3d _player_right;
Eigen::Vector3d _player_up;

Avril_FSD::Player::Player()
{
	Set_camera_FP(new class Avril_FSD::FirstPersonCamera());

	_isFirstMove = true;
	_isFirstMouseMove = false;
	_player_Position = { 0.0, 0.0, 0.0 };
	_player_mouse_Position = { 0.0, 0.0 };
	_player_front = { 0.0, 0.0, 0.0 };
	_player_right = { 0.0, 0.0, 0.0 };
	_player_up = { 0.0, 0.0, 0.0 };
	_cameraSelector = false;
	_cameraSpeed = 1.5f;
	_sensitivity = 0.2f;
}
Avril_FSD::Player::~Player()
{
}

Avril_FSD::FirstPersonCamera* Avril_FSD::Player::Get_camera_FP()
{
	return _camera_FP;
}

bool Avril_FSD::Player::Get_isFirstMove()
{
	return _isFirstMove;
}
bool Avril_FSD::Player::Get_isFirstMouseMove()
{
	return _isFirstMouseMove;
}
bool Avril_FSD::Player::Get_cameraSelector()
{
	return _cameraSelector;
}
float Avril_FSD::Player::Get_cameraSpeed()
{
	return _cameraSpeed;
}
float Avril_FSD::Player::Get_sensitivity()
{
	return _sensitivity;
}
std::vector<float> Avril_FSD::Player::Get_player_Position()
{
	return _player_Position;
}
std::vector<float> Avril_FSD::Player::Get_mouse_Position()
{
	return _player_mouse_Position;
}

Eigen::Vector3d Avril_FSD::Player::Get_Front()
{
	return _player_front;
}
Eigen::Vector3d Avril_FSD::Player::Get_Right()
{
	return _player_right;
}
Eigen::Vector3d Avril_FSD::Player::Get_Up()
{
	return _player_up;
}

void Avril_FSD::Player::Set_camera_FP(Avril_FSD::FirstPersonCamera* camera)
{
	_camera_FP = camera;
}
void Avril_FSD::Player::Set_isFirstMove(bool value)
{
	_isFirstMove = value;
}

void Avril_FSD::Player::Set_isFirstMouseMove(bool value)
{
	_isFirstMouseMove = value;
}

void Avril_FSD::Player::Set_cameraSpeed(float cameraSpeed)
{
	_cameraSpeed = cameraSpeed;
}

void Avril_FSD::Player::Set_sensitivity(float sensitivity)
{
	_sensitivity = sensitivity;
}

void Avril_FSD::Player::Set_player_Position_X(float position_X)
{
	_player_Position.at(0) = position_X;
}
void Avril_FSD::Player::Set_player_Position_Y(float position_Y)
{
	_player_Position.at(1) = position_Y;
}
void Avril_FSD::Player::Set_player_Position_Z(float position_Z)
{
	_player_Position.at(2) = position_Z;
}
void Avril_FSD::Player::Set_mouse_Position_X(float position_X)
{
	_player_mouse_Position.at(0) = position_X;
}
void Avril_FSD::Player::Set_mouse_Position_Y(float position_Y)
{
	_player_mouse_Position.at(1) = position_Y;
}

void Avril_FSD::Player::Set_front(Eigen::Vector3d front)
{
	_player_front = front;
}

void Avril_FSD::Player::Set_right(Eigen::Vector3d right)
{
	_player_right = right;
}

void Avril_FSD::Player::Set_up(Eigen::Vector3d up)
{
	_player_up = up;
}