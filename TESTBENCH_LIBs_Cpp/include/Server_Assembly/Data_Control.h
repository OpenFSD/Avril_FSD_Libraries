#pragma once
#include <vector>

namespace Avril_FSD
{
    class Data_Control
    {
    public:
        Data_Control();
        virtual ~Data_Control();
        void Pop_Stack_InputPraises(__int8 concurrentCoreId);
        void Pop_Stack_Output();
        void Push_Stack_InputPraises();
        void Push_Stack_Output(__int8 concurrentCoreId);
        
        bool GetFlag_InputStackLoaded();
        bool GetFlag_OutputStackLoaded();
        bool GetFlag_isNewInputDataReady();
        bool GetFlag_isNewOutputDataReady();

        void SetFlag_isNewInputDataReady(bool value);
        void SetFlag_isNewOutputDataReady(bool value);

    protected:

    private:
        void SetFlag_InputStackLoaded(bool value);
        void SetFlag_OutputStackLoaded(bool value);
    };
}