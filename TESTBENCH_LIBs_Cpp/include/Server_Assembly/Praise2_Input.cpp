#include "pch.h"

bool _fowards;
bool _backwards;
bool _left;
bool _right;
float period;

Avril_FSD::Praise2_Input::Praise2_Input()
{
	_fowards = false;
	_backwards = false;
	_left = false;
	_right = false;
	period = 0;
}

Avril_FSD::Praise2_Input::~Praise2_Input()
{

}
	
bool Avril_FSD::Praise2_Input::Get_fowards()
{
	return _fowards;
}
bool Avril_FSD::Praise2_Input::Get_backwards()
{
	return _backwards;
}
bool Avril_FSD::Praise2_Input::Get_left()
{
	return _left;
}
bool Avril_FSD::Praise2_Input::Get_right()
{
	return _right;
}
float Avril_FSD::Praise2_Input::Get_period()
{
	return period;
}
void Avril_FSD::Praise2_Input::Set_fowards(bool value)
{
	_fowards = value;
}
void Avril_FSD::Praise2_Input::Set_backwards(bool value)
{
	_backwards = value;
}
void Avril_FSD::Praise2_Input::Set_left(bool value)
{
	_left = value;
}
void Avril_FSD::Praise2_Input::Set_right(bool value)
{
	_right = value;
}
void Avril_FSD::Praise2_Input::Set_period(float value)
{
	period = value;
}