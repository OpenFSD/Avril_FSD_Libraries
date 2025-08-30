#include "pch.h"

float mouse_delta_X;
float mouse_delta_Y;

Avril_FSD::Praise1_Input::Praise1_Input()
{

}

Avril_FSD::Praise1_Input::~Praise1_Input()
{
}
float Avril_FSD::Praise1_Input::Get_mouse_X()
{
	return mouse_delta_X;
}
float Avril_FSD::Praise1_Input::Get_mouse_Y()
{
	return mouse_delta_Y;
}
void Avril_FSD::Praise1_Input::Set_mouse_X(float value)
{
	mouse_delta_X = value;
}
void Avril_FSD::Praise1_Input::Set_mouse_Y(float value)
{
	mouse_delta_Y = value;
}