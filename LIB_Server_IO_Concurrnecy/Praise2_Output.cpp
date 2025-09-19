#include "pch.h"

std::vector<float> _out2_position;
std::vector<float> _out2_fowards;
std::vector<float> _out2_right;
std::vector<float> _out2_up;

Avril_FSD::Praise2_Output::Praise2_Output()
{

}

Avril_FSD::Praise2_Output::~Praise2_Output()
{
}

std::vector<float> Avril_FSD::Praise2_Output::GetPosition()
{
	return _out2_position;
}

std::vector<float> Avril_FSD::Praise2_Output::GetFowards()
{
	return _out2_fowards;
}

std::vector<float> Avril_FSD::Praise2_Output::GetUp()
{
	return _out2_up;
}

std::vector<float> Avril_FSD::Praise2_Output::GetRight()
{
	return _out2_right;
}

void Avril_FSD::Praise2_Output::SetPosition(std::vector<float> position)
{
	_out2_position = position;
}

void Avril_FSD::Praise2_Output::SetFowards(std::vector<float> fowards)
{
	_out2_fowards = fowards;
}

void Avril_FSD::Praise2_Output::SetUp(std::vector<float> up)
{
	_out2_up = up;
}

void Avril_FSD::Praise2_Output::SetRight(std::vector<float> right)
{
	_out2_right = right;
}
