// TESTBENCH_LIBs_Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "include\Server_Assembly\Framework_Server.h"
#include "include\Server_Assembly\LIB_Server_Assembly.h"

int main()
{
    std::cout << "Hello World!\n";
    class Avril_FSD::Framework_Server* framework_Server_Assembly = Avril_FSD::LIB_ServerLibrary::Initialise_Server_Assembly();
     
    Avril_FSD::LIB_ServerLibrary::Set_PraiseEventId(0);
    Avril_FSD::LIB_ServerLibrary::Set_Praise0_Input_IsPingActive(true);
    Avril_FSD::LIB_ServerLibrary::Set_Flag_isNewInputDataReady(true);

}