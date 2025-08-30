#include "pch.h"

float mouse_X;
float mouse_Y;

Avril_FSD::Praise1_Input::Praise1_Input()
{

}

Avril_FSD::Praise1_Input::~Praise1_Input()
{
}
float Avril_FSD::Praise1_Input::Get_mouse_X()
{
	return mouse_X;
}
float Avril_FSD::Praise1_Input::Get_mouse_Y()
{
	return mouse_Y;
}
void Avril_FSD::Praise1_Input::Set_mouse_X(float value)
{
	mouse_X = value;
}
void Avril_FSD::Praise1_Input::Set_mouse_Y(float value)
{
	mouse_Y = value;
}