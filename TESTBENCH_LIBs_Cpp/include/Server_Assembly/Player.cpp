#include "pch.h"

bool _firstMove;

bool isPlayerMoved;
std::vector<float> player_Position;
std::vector<float> _Front;
std::vector<float> _Right;
std::vector<float> _Up;

bool isMouseChanged;
std::vector<float> mouse_Position;

float cameraSpeed;
float sensitivity;

Avril_FSD::Player::Player()
{
	_firstMove = true;
	isPlayerMoved = false;
	player_Position = { 0.0, 0.0, 0.0 };
	_Front = { 0.0, 0.0, 0.0 };
	_Right = { 0.0, 0.0, 0.0 };
	_Up = { 0.0, 0.0, 0.0 };
	isMouseChanged = false;
	mouse_Position = { 0.0, 0.0 };
	cameraSpeed = 1.5f;
	sensitivity = 0.2f;
}
Avril_FSD::Player::~Player()
{
}

bool Avril_FSD::Player::Get_isMouseChanged()
{
	return isMouseChanged;
}
bool Avril_FSD::Player::Get_isFirstMove()
{
	return _firstMove;
}
std::vector<float> Avril_FSD::Player::Get_Front()
{
	return _Front;
}
std::vector<float> Avril_FSD::Player::Get_Right()
{
	return _Right;
}
std::vector<float> Avril_FSD::Player::Get_Up()
{
	return _Up;
}
std::vector<float> Avril_FSD::Player::Get_MousePos()
{
	return mouse_Position;
}
std::vector<float> Avril_FSD::Player::Get_PlayerPosition()
{
	return player_Position;
}
float Avril_FSD::Player::Get_CameraSpeed()
{
	return cameraSpeed;
}
float Avril_FSD::Player::Get_Sensativity()
{
	return sensitivity;
}
void Avril_FSD::Player::Set_isFirstMove(bool value)
{
	_firstMove = value;
}
void Avril_FSD::Player::Set_MousePos(std::vector<float> value)
{
	mouse_Position = value;
}
void Avril_FSD::Player::Set_PlayerPosition(std::vector<float> value)
{
	player_Position = value;
}