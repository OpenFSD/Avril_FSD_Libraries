#include "pch.h"

float _fov;
int _refreshRate;
bool _systemInitialised;
char _screenSize_X;
char _screenSize_Y;

Avril_FSD::Settings::Settings()
{
	_fov = 45;
	_refreshRate = 144;
	_systemInitialised = false;
	_screenSize_X = (float)1920;
	_screenSize_Y = (float)1080;
}

Avril_FSD::Settings::~Settings()
{
}

float Avril_FSD::Settings::Get_fov()
{
	return _fov;
}
int Avril_FSD::Settings::Get_refreshRate()
{
	return _refreshRate;
}
bool Avril_FSD::Settings::Get_systemInitialised()
{
	return _systemInitialised;
}
char Avril_FSD::Settings::Get_screenSize_X()
{
	return _screenSize_X;
}
char Avril_FSD::Settings::Get_screenSize_Y()
{
	return _screenSize_Y;
}

void Avril_FSD::Settings::Set_fov(float fov)
{
	_fov = fov;
}
void Avril_FSD::Settings::Set_refreshRate(int refreshRate)
{
	_refreshRate = refreshRate;
}
void Avril_FSD::Settings::Set_systemInitialised(bool isSystemInitialised)
{
	_systemInitialised = isSystemInitialised;
}
void Avril_FSD::Settings::Set_screenSize_X(char screenSize_X)
{
	_screenSize_X = screenSize_X;
}
void Avril_FSD::Settings::Set_screenSize_Y(char screenSize_Y)
{
	_screenSize_Y = screenSize_Y;
}
