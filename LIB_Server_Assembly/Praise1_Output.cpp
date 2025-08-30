#include "pch.h"
#include <array>
#include <cstddef>

std::array<float, 3> _out1_fowards;
std::array<float, 3> _out1_right;
std::array<float, 3> _out1_up;

Avril_FSD::Praise1_Output::Praise1_Output()
{

}

Avril_FSD::Praise1_Output::~Praise1_Output()
{
}

std::array<float, 3> Avril_FSD::Praise1_Output::GetFowards()
{
	return _out1_fowards;
}

std::array<float, 3> Avril_FSD::Praise1_Output::GetUp()
{
	return _out1_up;
}
std::array<float, 3> Avril_FSD::Praise1_Output::GetRight()
{
	return _out1_right;
}

void Avril_FSD::Praise1_Output::SetFowards(std::array<float, 3> fowards)
{
	_out1_fowards = fowards;
}

void Avril_FSD::Praise1_Output::SetUp(std::array<float, 3> up)
{
	_out1_up = up;
}

void Avril_FSD::Praise1_Output::SetRight(std::array<float, 3> right)
{
	_out1_right = right;
}
