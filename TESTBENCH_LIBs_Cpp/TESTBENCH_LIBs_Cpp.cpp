// TESTBENCH_LIBs_Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "include\Server_Assembly\Framework_Server.h"
#include "include\Server_Assembly\LIB_Server_Assembly.h"
//#include "include/ConcurrentQue_Client/ConcurrentQue_Client_Framework.h"
//#include "include/ConcurrentQue_Client/LIB_ConcurrentQue_Client.h"

int main()
{
    std::cout << "Hello World!\n";
    class Avril_FSD::Framework_Server* framework_Server_Assembly = Avril_FSD::LIB_ServerLibrary::Initialise_Server_Assembly();
    Avril_FSD::LIB_ServerLibrary::Initialise_Server_Assembly();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
