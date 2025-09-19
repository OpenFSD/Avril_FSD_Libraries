#include "pch.h"

std::vector<class Avril_FSD::Player*> _player;
class Avril_FSD::Settings* _settings;

Avril_FSD::GameInstance::GameInstance()
{
	_player.resize(2);
	Set_settings(new class Avril_FSD::Settings());
}

Avril_FSD::GameInstance::~GameInstance()
{
}

Avril_FSD::Player* Avril_FSD::GameInstance::Get_player(__int8 playerId)
{
	return _player.at(playerId);
}

Avril_FSD::Settings* Avril_FSD::GameInstance::Get_settings()
{
	return _settings;
}

void Avril_FSD::GameInstance::Set_player(class Avril_FSD::Player* player)
{
	_player.push_back(player);
}

void Avril_FSD::GameInstance::Set_settings(class Avril_FSD::Settings* settings)
{
	_settings = settings;
}
