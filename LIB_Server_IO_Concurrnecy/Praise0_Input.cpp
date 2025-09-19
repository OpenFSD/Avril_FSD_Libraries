#include "pch.h"

bool pingIn_Active;

Avril_FSD::Praise0_Input::Praise0_Input()
{
	pingIn_Active = false;
}

Avril_FSD::Praise0_Input::~Praise0_Input()
{
	
}

bool Avril_FSD::Praise0_Input::Get_ping_Active()
{
	return pingIn_Active;
}

void Avril_FSD::Praise0_Input::Set_ping_Active(bool value)
{
	pingIn_Active = value;
}