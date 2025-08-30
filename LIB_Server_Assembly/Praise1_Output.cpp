#include "pch.h"

#include <cstddef>

std::vector<float> _out1_fowards;
std::vector<float> _out1_right;
std::vector<float> _out1_up;

Avril_FSD::Praise1_Output::Praise1_Output()
{

}

Avril_FSD::Praise1_Output::~Praise1_Output()
{
}

std::vector<float> Avril_FSD::Praise1_Output::GetFowards()
{
	return _out1_fowards;
}

std::vector<float> Avril_FSD::Praise1_Output::GetUp()
{
	return _out1_up;
}

std::vector<float> Avril_FSD::Praise1_Output::GetRight()
{
	return _out1_right;
}

void Avril_FSD::Praise1_Output::SetFowards(std::vector<float> fowards)
{
	_out1_fowards = fowards;
}

void Avril_FSD::Praise1_Output::SetUp(std::vector<float> up)
{
	_out1_up = up;
}

void Avril_FSD::Praise1_Output::SetRight(std::vector<float> right)
{
	_out1_right = right;
}
