#include "pch.h"

#include <cstddef>
#include <vector>

bool state_ConcurrentCore[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
bool flag_praisingLaunch = NULL;
unsigned char concurrent_CoreId_Index = NULL;
int count_LaunchActive_For[3] = { NULL, NULL, NULL };//NUMBER OF CONCURNT CORES
int count_LaunchIdle_For[3] = { NULL, NULL, NULL };//NUMBER OF CONCURNT CORES
unsigned char new_concurrent_CoreId_Index = NULL;
unsigned char que_CoreToLaunch[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    
std::vector<unsigned char>* stack_PriseEventId;

Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::ConcurrentQue_Client_LaunchConcurrency_Control(
    Avril_FSD::ConcurrentQue_Client_Global* ptr_Global,
    unsigned char number_Implemented_Cores
)
{
    state_ConcurrentCore[3] = {bool(false)};//NUMBER OF CONCURRENT CORES
    flag_praisingLaunch = bool(false);
    concurrent_CoreId_Index = unsigned char(0);
    count_LaunchActive_For[3] = {int(0)};//NUMBER OF CONCURNT CORES
    count_LaunchIdle_For[3] = {int(0)};//NUMBER OF CONCURNT CORES
    new_concurrent_CoreId_Index = unsigned char(0);
    que_CoreToLaunch[3] = {unsigned char(0)};//NUMBER OF CONCURNT CORES
    for (unsigned char index = 0; index < (number_Implemented_Cores-1); index++)
    {
        state_ConcurrentCore[index] = ptr_Global->GetConst_Core_IDLE();
        count_LaunchActive_For[index] = int(0);
        count_LaunchIdle_For[index] = int(0);
        que_CoreToLaunch[index] = index;
    }
    stack_PriseEventId = new std::vector<unsigned char>;
}

Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::~ConcurrentQue_Client_LaunchConcurrency_Control()
{

}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::LaunchEnable_Activate(
    class Avril_FSD::ConcurrentQue_Client_Global* ptr_Global
)
{
    SetFlag_ConcurrentCoreState(GetFlag_CoreId_Of_CoreToLaunch(), ptr_Global->GetConst_Core_ACTIVE());
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::LaunchEnable_Request(
    unsigned char concurrent_CoreId,
    class Avril_FSD::ConcurrentQue_Client_Global* ptr_Global
)
{
    while (Get_State_ConcurrentCore(GetFlag_CoreId_Of_CoreToLaunch()) != ptr_Global->GetConst_Core_IDLE())
    {

    }
    while (GetFlag_PraisingLaunch() == true)
    {
        DynamicStagger(concurrent_CoreId);
    }
    SetFlag_PraisingLaunch(true);
    Set_concurrent_CoreId_Index(Get_new_concurrent_CoreId_Index());
    if (Get_concurrent_CoreId_Index() == concurrent_CoreId)
    {

    }
    else
    {
        Set_new_concurrent_CoreId_Index(Get_concurrent_CoreId_Index() + 1);
        if (Get_concurrent_CoreId_Index() == 3)
        {
            Set_new_concurrent_CoreId_Index(0);
        }
        SetFlag_PraisingLaunch(false);
        LaunchEnable_Request(
            concurrent_CoreId,
            ptr_Global
        );
    }
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::LaunchEnable_SortQue(
    class Avril_FSD::ConcurrentQue_Client_Global* ptr_Global,
    unsigned char number_Implemented_Cores
)
{
    for (unsigned char index_A = 0; index_A < number_Implemented_Cores - 2; index_A++)
    {
        for (unsigned char index_B = index_A + 1; index_B < number_Implemented_Cores - 1; index_B++)
        {
            if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_A)) == ptr_Global->GetConst_Core_ACTIVE())
            {
                if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_B)) == ptr_Global->GetConst_Core_IDLE())
                {
                    LaunchEnable_ShiftQueValues(index_A, index_B);
                }
                else if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_B)) == ptr_Global->GetConst_Core_ACTIVE())
                {
                    if (Get_count_LaunchActive_For(index_A) > Get_count_LaunchActive_For(index_B))
                    {
                        LaunchEnable_ShiftQueValues(index_A, index_B);
                    }
                }
            }
            else if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_A)) == ptr_Global->GetConst_Core_IDLE())

                if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_B)) == ptr_Global->GetConst_Core_IDLE())
                {
                    if (Get_count_LaunchIdle_For(index_A) < Get_count_LaunchIdle_For(index_B))
                    {
                        LaunchEnable_ShiftQueValues(index_A, index_B);
                    }
                }
        }
    }
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::LaunchQue_Update(
    unsigned char number_Implemented_Cores
)
{
    for (unsigned char index = 0; index < number_Implemented_Cores; index++)
    {
        switch (Get_State_ConcurrentCore(index))
        {
        case false:
        {
            Set_count_LaunchActive_For(index, 0);
            Set_count_LaunchIdle_For(index, Get_count_LaunchIdle_For(index) + 1);
            break;
        }
        case true:
        {
            Set_count_LaunchActive_For(index, Get_count_LaunchActive_For(index) + 1);
            Set_count_LaunchIdle_For(index, 0);
            break;
        }
        }
    }
}

unsigned char Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Get_concurrent_CoreId_Index()
{
    return concurrent_CoreId_Index;
}

unsigned char Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Get_coreId_To_Launch()
{
    return que_CoreToLaunch[0];
}

bool Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Get_State_ConcurrentCore(unsigned char concurrent_CoreId)
{
    return state_ConcurrentCore[concurrent_CoreId];
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::SetFlag_PraisingLaunch(bool value)
{
    flag_praisingLaunch = value;
}

unsigned char Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Get_new_concurrent_CoreId_Index()
{
    return new_concurrent_CoreId_Index;
}

std::vector<unsigned char>* Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Get_Stack_PriseEventId()
{
    return stack_PriseEventId;
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Set_concurrent_CoreId_Index(unsigned char value)
{
    concurrent_CoreId_Index = value;
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::SetFlag_ConcurrentCoreState(unsigned char concurrent_CoreId, bool value)
{
    state_ConcurrentCore[concurrent_CoreId] = value;
}


bool Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::GetFlag_PraisingLaunch()
{
    return flag_praisingLaunch;
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Set_new_concurrent_CoreId_Index(unsigned char value)
{
    new_concurrent_CoreId_Index = value;
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::DynamicStagger(
    unsigned char ptr_coreId
)
{
    if (Get_concurrent_CoreId_Index() == ptr_coreId)
    {
        //exit early
    }
    else
    {
        int ptr_count = int(0);
        while (ptr_count < 20)//todo time till flag change
        {

            ptr_count = ptr_count + 1;
        }
    }
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::LaunchEnable_ShiftQueValues(
    unsigned char concurrent_CoreId_A,
    unsigned char concurrent_CoreId_B
)
{
    int temp_Int;// = new int(0);
    temp_Int = Get_count_LaunchActive_For(concurrent_CoreId_A);
    Set_count_LaunchActive_For(concurrent_CoreId_A, Get_count_LaunchActive_For(concurrent_CoreId_B));
    Set_count_LaunchActive_For(concurrent_CoreId_B, temp_Int);

    temp_Int = Get_count_LaunchIdle_For(concurrent_CoreId_A);
    Set_count_LaunchIdle_For(concurrent_CoreId_A, Get_count_LaunchIdle_For(concurrent_CoreId_B));
    Set_count_LaunchIdle_For(concurrent_CoreId_B, temp_Int);

    unsigned char temp_UnnsignedChar;// = new unsigned char(0);
    temp_UnnsignedChar = Get_que_CoreToLaunch(concurrent_CoreId_A);
    Set_que_CoreToLaunch(concurrent_CoreId_A, Get_que_CoreToLaunch(concurrent_CoreId_B));
    Set_que_CoreToLaunch(concurrent_CoreId_B, temp_UnnsignedChar);
}

int Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Get_count_LaunchActive_For(unsigned char concurrent_CoreId)
{
    return count_LaunchActive_For[concurrent_CoreId];
}

int Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Get_count_LaunchIdle_For(unsigned char concurrent_CoreId)
{
    return count_LaunchIdle_For[concurrent_CoreId];
}

unsigned char Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::GetFlag_CoreId_Of_CoreToLaunch()
{
    return que_CoreToLaunch[0];
}

unsigned char Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Get_que_CoreToLaunch(unsigned char index)
{
    return que_CoreToLaunch[index];
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Set_count_LaunchActive_For(unsigned char concurrent_CoreId, int value)
{
    count_LaunchActive_For[concurrent_CoreId] = value;
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Set_count_LaunchIdle_For(unsigned char concurrent_CoreId, int value)
{
    count_LaunchIdle_For[concurrent_CoreId] = value;
}

void Avril_FSD::ConcurrentQue_Client_LaunchConcurrency_Control::Set_que_CoreToLaunch(unsigned char concurrent_CoreId, unsigned char value)
{
    que_CoreToLaunch[concurrent_CoreId] = value;
}