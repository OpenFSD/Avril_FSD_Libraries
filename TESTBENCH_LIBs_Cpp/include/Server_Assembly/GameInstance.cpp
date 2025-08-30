#include "pch.h"

#include <cstddef>

std::vector<class Avril_FSD::Player*> _player;

Avril_FSD::GameInstance::GameInstance()
{
	_player.resize(2);
}

Avril_FSD::GameInstance::~GameInstance()
{
}

Avril_FSD::Player* Avril_FSD::GameInstance::GetPlayer(__int8 playerId)
{
	return _player.at(playerId);
}

void Avril_FSD::GameInstance::Set_player(Avril_FSD::Player* player)
{
	_player.push_back(player);
}