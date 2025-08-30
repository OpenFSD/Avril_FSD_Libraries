#include "pch.h"

#include <cstddef>

class Avril_FSD::Praise0_Output* ptr_Praise0_Output = NULL;
class Avril_FSD::Praise1_Output* ptr_Praise1_Output = NULL;
class Avril_FSD::Praise2_Output* ptr_Praise2_Output = NULL;

Avril_FSD::User_O::User_O()
{
	//Set_Praise0_Output(new class Avril_FSD::Praise0_Output());
	//while (Get_Praise0_Output() == NULL) { }

	//Set_Praise1_Output(new class Avril_FSD::Praise1_Output());
	//while (Get_Praise1_Output() == NULL) { }

	//Set_Praise2_Output(new class Avril_FSD::Praise2_Output());
	//while (Get_Praise2_Output() == NULL) { }
}
Avril_FSD::User_O::~User_O()
{
	delete ptr_Praise0_Output;
}

class Avril_FSD::Praise0_Output* Avril_FSD::User_O::Get_Praise0_Output()
{
	return ptr_Praise0_Output;
}
class Avril_FSD::Praise1_Output* Avril_FSD::User_O::Get_Praise1_Output()
{
	return ptr_Praise1_Output;
}
class Avril_FSD::Praise2_Output* Avril_FSD::User_O::Get_Praise2_Output()
{
	return ptr_Praise2_Output;
}
void Avril_FSD::User_O::Set_Praise0_Output(Avril_FSD::Praise0_Output* praise0_O)
{
	ptr_Praise0_Output = praise0_O;
}
void Avril_FSD::User_O::Set_Praise1_Output(Avril_FSD::Praise1_Output* praise1_O)
{
	ptr_Praise1_Output = praise1_O;
}
void Avril_FSD::User_O::Set_Praise2_Output(Avril_FSD::Praise2_Output* praise2_O)
{
	ptr_Praise2_Output = praise2_O;
}