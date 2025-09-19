#include "pch.h"

Avril_FSD::Praise0_Input* ptr_Praise0_Input = NULL;
Avril_FSD::Praise1_Input* ptr_Praise1_Input = NULL;
Avril_FSD::Praise2_Input* ptr_Praise2_Input = NULL;

Avril_FSD::User_I::User_I()
{
	Set_Praise0_Input(new class Avril_FSD::Praise0_Input());
	while (Get_Praise0_Input() == NULL) { }

	Set_Praise1_Input(new class Avril_FSD::Praise1_Input());
	while (Get_Praise1_Input() == NULL) { }

	Set_Praise2_Input(new class Avril_FSD::Praise2_Input());
	while (Get_Praise2_Input() == NULL) { }
}
Avril_FSD::User_I::~User_I()
{
	delete ptr_Praise0_Input;
	delete ptr_Praise1_Input;
	delete ptr_Praise2_Input;
}

Avril_FSD::Praise0_Input* Avril_FSD::User_I::Get_Praise0_Input()
{
	return ptr_Praise0_Input;
}
Avril_FSD::Praise1_Input* Avril_FSD::User_I::Get_Praise1_Input()
{
	return ptr_Praise1_Input;
}
Avril_FSD::Praise2_Input* Avril_FSD::User_I::Get_Praise2_Input()
{
	return ptr_Praise2_Input;
}
void Avril_FSD::User_I::Set_Praise0_Input(Praise0_Input* praise0_I)
{
	ptr_Praise0_Input = praise0_I;
}
void Avril_FSD::User_I::Set_Praise1_Input(Praise1_Input* praise1_I)
{
	ptr_Praise1_Input = praise1_I;
}
void Avril_FSD::User_I::Set_Praise2_Input(Praise2_Input* praise2_I)
{
	ptr_Praise2_Input = praise2_I;
}