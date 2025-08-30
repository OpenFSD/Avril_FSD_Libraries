#pragma once

namespace Avril_FSD
{
    class Output_Control
    {
    public:
        Output_Control();
        virtual ~Output_Control();

        void SelectSet_Output_Subset(__int8 ptr_praiseEventId, __int8 concurrent_coreId);

    protected:

    private:

    };
}