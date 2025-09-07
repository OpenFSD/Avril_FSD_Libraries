#pragma once

namespace Avril_FSD
{
    class WriteEnable_ServerInputAction
    {
    public:
        WriteEnable_ServerInputAction();
        virtual ~WriteEnable_ServerInputAction();
        void Initialise_Control();

        void Write_End(class WriteEnable_ServerInputAction_Framework* obj, unsigned char coreId);
        void Write_Start(class WriteEnable_ServerInputAction_Framework* obj, unsigned char coreId);

        static class WriteEnable_ServerInputAction_Global* Get_global();
        static class WriteEnable_ServerInputAction_Control* Get_writeEnable_Control();

    private:
        static void Set_global(class WriteEnable_ServerInputAction_Global* global);
        static void Set_writeEnable_Control(class WriteEnable_ServerInputAction_Control* writeEnableControl);
    };
}
