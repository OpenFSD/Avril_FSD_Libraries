#include "pch.h"

#include <cstddef>

class Avril_FSD::Praise0_Algorithm* ptr_Praise0_Algorithm = NULL;
class Avril_FSD::Praise1_Algorithm* ptr_Praise1_Algorithm = NULL;
class Avril_FSD::Praise2_Algorithm* ptr_Praise2_Algorithm = NULL;

Avril_FSD::User_Alg::User_Alg()
{
	Set_Praise0_Algorithm(new class Avril_FSD::Praise0_Algorithm());
	while (Get_Praise0_Algorithm() == NULL) {  }

	Set_Praise1_Algorithm(new class Avril_FSD::Praise1_Algorithm());
	while (Get_Praise1_Algorithm() == NULL) {  }

	Set_Praise2_Algorithm(new class Avril_FSD::Praise2_Algorithm());
	while (Get_Praise2_Algorithm() == NULL) {  }
}
Avril_FSD::User_Alg::~User_Alg()
{
	delete ptr_Praise0_Algorithm;
}

Avril_FSD::Praise0_Algorithm* Avril_FSD::User_Alg::Get_Praise0_Algorithm()
{
	return ptr_Praise0_Algorithm;
}

Avril_FSD::Praise1_Algorithm* Avril_FSD::User_Alg::Get_Praise1_Algorithm()
{
	return ptr_Praise1_Algorithm;
}
Avril_FSD::Praise2_Algorithm* Avril_FSD::User_Alg::Get_Praise2_Algorithm()
{
	return ptr_Praise2_Algorithm;
}

void Avril_FSD::User_Alg::Set_Praise0_Algorithm(Avril_FSD::Praise0_Algorithm* praise0_A)
{
	ptr_Praise0_Algorithm = praise0_A;
}

void Avril_FSD::User_Alg::Set_Praise1_Algorithm(Avril_FSD::Praise1_Algorithm* praise1_A)
{
	ptr_Praise1_Algorithm = praise1_A;
}

void Avril_FSD::User_Alg::Set_Praise2_Algorithm(Avril_FSD::Praise2_Algorithm* praise2_A)
{
	ptr_Praise2_Algorithm = praise2_A;
}
