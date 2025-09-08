#include "include/LIB_LaunchEnableForConcurrentThreadsAt_SERVER/LIB_LaunchEnableForConcurrentThreadsAt_SERVER.h"
#include "include/LIB_WriteEnableForThreadsAt_SERVERINPUTACTION/LIB_WriteEnableForThreadsAt_SERVERINPUTACTION.h"
#include "include/LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE/LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE.h"

#include <iostream>

int main()
{
    std::cout << "Starting TESTBENCH\n";
    void* program_ServerLaunchQue = Avril_FSD::CLIBLaunchEnableForConcurrentThreadsAtSERVER::Initialise_LaunchEnableForConcurrentThreadsAt();
    while(program_ServerLaunchQue == NULL) { }
    void* program_InputActionServerWriteQue = Avril_FSD::Library_WriteEnableForThreadsAt_SERVERINPUTACTION::Initialise_WriteEnable();
    while (program_InputActionServerWriteQue == NULL) {}
    void* program_OutputRecieveServerWriteQue = Avril_FSD::Library_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE::Initialise_WriteEnable();
    while (program_OutputRecieveServerWriteQue == NULL) {}
    std::cout << "initilisation library test -done.\n";
}