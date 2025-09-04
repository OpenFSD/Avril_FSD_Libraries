#include "include/ConcurrentQue_END/ConcurrentQue_END_Framework.h"
#include "include/ConcurrentQue_END/ConcurrentQue_END_Global.h"
#include "include/ConcurrentQue_END/ConcurrentQue_END.h"
#include "include/ConcurrentQue_END/ConcurrentQue_END_Control.h"
#include <iostream>

int main()
{
    std::cout << "Starting TESTBENCH\n";
    Avril_FSD::ConcurrentQue_END_Framework* concurrentQue_END_Framework = new class Avril_FSD::ConcurrentQue_END_Framework();
    __int8 coreId_to_launch = concurrentQue_END_Framework->Get_ConcurrentQue()->Get_Control_Of_LaunchConcurrency()->Get_flag_CoreId_Of_CoreToLaunch();
    std::cout << "coreId_to_launch = " << coreId_to_launch << ".\n";
}