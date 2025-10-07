#include "pch.h"

class Avril_FSD::Concurrent* ptr_Concurrent[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
class Avril_FSD::Concurrent* ptr_New_Concurrent = NULL;
class Avril_FSD::User_Alg* ptr_User_Algorithms = NULL;

Avril_FSD::Algorithms::Algorithms()
{
    Set_User_Algorithms(new class User_Alg());
    while (Get_User_Algorithms() == NULL) { }
}

Avril_FSD::Algorithms::~Algorithms()
{
    for (__int8 index = 0; index < 4; index++)//NUMBER OF CONCURRENT CORES
    {
        delete ptr_Concurrent[index];
    }
    delete ptr_User_Algorithms;;
}

void Avril_FSD::Algorithms::Initialise(__int8 number_Implemented_Cores)
{
    Set_New_Concurrent(new class Avril_FSD::Concurrent());
    while(Get_New_Concurrent() == NULL) { /* wait untill created */ }
    Get_New_Concurrent()->Initialise_Control();

    for (__int8 index = 0; index < (number_Implemented_Cores); index++)
    {
        Set_Concurrent(Get_New_Concurrent(), index);
    }
    delete ptr_New_Concurrent;
}

Avril_FSD::Concurrent* Avril_FSD::Algorithms::Get_Concurrent(__int8 index)
{
    return ptr_Concurrent[index];
}
Avril_FSD::Concurrent* Avril_FSD::Algorithms::Get_New_Concurrent()
{
    return ptr_New_Concurrent;
}
Avril_FSD::User_Alg* Avril_FSD::Algorithms::Get_User_Algorithms()
{
    return ptr_User_Algorithms;
}
void Avril_FSD::Algorithms::Set_Concurrent(Concurrent* concurrent, __int8 indexCount)
{
}
void Avril_FSD::Algorithms::Set_New_Concurrent(Concurrent* concurrent)
{
}
void Avril_FSD::Algorithms::Set_User_Algorithms(User_Alg* user_Algorithms)
{
}