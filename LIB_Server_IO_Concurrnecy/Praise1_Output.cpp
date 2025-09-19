#include "pch.h"

Eigen::Vector3d _out1_fowards;
Eigen::Vector3d _out1_right;
Eigen::Vector3d _out1_up;

Avril_FSD::Praise1_Output::Praise1_Output()
{

}

Avril_FSD::Praise1_Output::~Praise1_Output()
{
}

Eigen::Vector3d Avril_FSD::Praise1_Output::GetFowards()
{
	return _out1_fowards;
}

Eigen::Vector3d Avril_FSD::Praise1_Output::GetUp()
{
	return _out1_up;
}
Eigen::Vector3d Avril_FSD::Praise1_Output::GetRight()
{
	return _out1_right;
}

void Avril_FSD::Praise1_Output::SetFowards(Eigen::Vector3d fowards)
{
	_out1_fowards = fowards;
}

void Avril_FSD::Praise1_Output::SetUp(Eigen::Vector3d up)
{
	_out1_up = up;
}

void Avril_FSD::Praise1_Output::SetRight(Eigen::Vector3d right)
{
	_out1_right = right;
}
