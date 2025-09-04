#include "include/ConcurrentQue_END/ConcurrentQue_END_Framework.h"
//#include "include/ConcurrentQue_END/ConcurrentQue_END_Global.h"
//#include "include/ConcurrentQue_END/ConcurrentQue_END.h"
//#include "include/ConcurrentQue_END/ConcurrentQue_END_Control.h"
#include "include/WriteEnable_STACK/WriteEnable_STACK_Framework.h"
//#include "include/WriteEnable_STACK/WriteEnable_STACK_Global.h"
//#include "include/WriteEnable_STACK/WriteEnable_STACK.h"
//#include "include/WriteEnable_STACK/WriteEnable_STACK_Control.h"
#include <iostream>

int main()
{
    std::cout << "Starting TESTBENCH\n";
    Avril_FSD::ConcurrentQue_END_Framework* concurrentQue_END_Framework = new class Avril_FSD::ConcurrentQue_END_Framework();
    
    Avril_FSD::WriteEnable_STACK_Framework* writeEnable_STACK_Framework = new class Avril_FSD::WriteEnable_STACK_Framework();
}