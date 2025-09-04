#include "include/ConcurrentQue_END/ConcurrentQue_END_Framework.h"
#include "include/ConcurrentQue_END/LIB_LaunchEnableForConcurrentThreadsAt_END.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    void* framework_Server_Assembly = Avril_FSD::ConcurrentQue_END_Library::Initialise_ConcurrentQue();
    class Avril_FSD::ConcurrentQue_END_Framework* obj = (Avril_FSD::ConcurrentQue_END_Framework*)framework_Server_Assembly;
    bool launchState = false;
    launchState = Avril_FSD::ConcurrentQue_END_Library::Get_State_LaunchBit(obj);
    std::cout << "launchState = " << launchState << ".";
}