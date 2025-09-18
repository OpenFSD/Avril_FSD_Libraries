#include "pch.h"

bool ping_Active;

Avril_FSD::Praise0_Output::Praise0_Output()
{
	ping_Active = false;
}

Avril_FSD::Praise0_Output::~Praise0_Output()
{
}
bool Avril_FSD::Praise0_Output::Get_ping_Active()
{
	return ping_Active;
}
void Avril_FSD::Praise0_Output::Set_ping_Active(bool value)
{
	ping_Active = value;
}