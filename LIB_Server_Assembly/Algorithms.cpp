#include "pch.h"

#include <cstddef>

namespace Avril_FSD
{
    class Concurrent* ptr_Concurrent[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Concurrent* ptr_New_Concurrent = NULL;
    class User_Alg* ptr_User_Algorithms = NULL;

    Algorithms::Algorithms()
    {
        Set_User_Algorithms(new class User_Alg());
        while (Get_User_Algorithms() == NULL) { }
    }

    Algorithms::~Algorithms()
    {
        for (__int8 index = 0; index < 4; index++)//NUMBER OF CONCURRENT CORES
        {
            delete ptr_Concurrent[index];
        }
        delete ptr_New_Concurrent;
        delete ptr_User_Algorithms;;
    }

    void Algorithms::Initialise(__int8 number_Implemented_Cores)
    {
        Set_New_Concurrent(new class Avril_FSD::Concurrent());
        while(Get_New_Concurrent() == NULL) { /* wait untill created */ }
        Get_New_Concurrent()->Initialise_Control();

        for (__int8 index = 0; index < (number_Implemented_Cores - 1); index++)
        {
            Set_Concurrent(Get_New_Concurrent(), index);
        }
        delete ptr_New_Concurrent;
    }

    Concurrent* Algorithms::Get_Concurrent(__int8 index)
    {
        return ptr_Concurrent[index];
    }
    Concurrent* Avril_FSD::Algorithms::Get_New_Concurrent()
    {
        return nullptr;
    }
    User_Alg* Algorithms::Get_User_Algorithms()
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
}