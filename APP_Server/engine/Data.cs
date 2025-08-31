using System;
using System.Collections.Generic;

namespace Avril_FSD_ServerAssembly
{
    public class Data
    {
        Avril_FSD_ServerAssembly.Data_Control data_Control;
        Avril_FSD_ServerAssembly.Game_Instance gameInstance;
        Avril_FSD_ServerAssembly.Settings settings;
        //byffers
        Avril_FSD_ServerAssembly.Input_Instance input_Instnace;
        Avril_FSD_ServerAssembly.Output_Instance output_Instnace;
        //stacks        
        List<Avril_FSD_ServerAssembly.Input> stack_InputPraise;
        List<Avril_FSD_ServerAssembly.Output> stack_OutputPraise;
        //praises
        Avril_FSD_ServerAssembly.User_I user_I;
        Avril_FSD_ServerAssembly.User_O user_O;

        bool state_Buffer_InputPraise_SideToWrite;
        bool state_Buffer_OutputPraise_SideToWrite;

        public Data()
        {
            data_Control = null;
            gameInstance = new Avril_FSD_ServerAssembly.Game_Instance();
            while (gameInstance == null) { /* Wait while is created */ }

            settings = new Avril_FSD_ServerAssembly.Settings();
            while (settings == null) { /* Wait while is created */ }

            input_Instnace = new Avril_FSD_ServerAssembly.Input_Instance();
            output_Instnace = new Avril_FSD_ServerAssembly.Output_Instance();

            user_I = new Avril_FSD_ServerAssembly.User_I();
            while (user_I == null) { /* Wait while is created */ }

            user_O = new Avril_FSD_ServerAssembly.User_O();
            while (user_O == null) { /* Wait while is created */ }

            state_Buffer_InputPraise_SideToWrite = true;
            state_Buffer_OutputPraise_SideToWrite = false;
         
            System.Console.WriteLine("Avril_FSD_ServerAssembly: Data");
        }

        public Int16 BoolToInt16(bool value)
        {
            Int16 temp = new Int16();
            if (value)
            {
                temp = (Int16)1;
            }
            else if (!value)
            {
                temp = (Int16)0;
            }
            return temp;
        }
        
        public void InitialiseControl()
        {
            data_Control = new Avril_FSD_ServerAssembly.Data_Control();
            while (data_Control == null) { /* Wait while is created */ }
        }

        public void Flip_InBufferToWrite()
        {
            state_Buffer_InputPraise_SideToWrite = !state_Buffer_InputPraise_SideToWrite;
        }
        public void Flip_OutBufferToWrite()
        {
            state_Buffer_OutputPraise_SideToWrite = !state_Buffer_OutputPraise_SideToWrite;
        }

        public Avril_FSD_ServerAssembly.Data_Control GetData_Control()
        {
            return data_Control;
        }
        public Avril_FSD_ServerAssembly.Game_Instance GetGame_Instance()
        {
            return gameInstance;
        }
        public Avril_FSD_ServerAssembly.Input_Instance GetInput_Instnace()
        {
            return input_Instnace;
        }
        public Avril_FSD_ServerAssembly.Output_Instance GetOutput_Instnace()
        {
            return output_Instnace;
        }
        public bool GetState_Buffer_InputPraise_SideToWrite()
        {
            return state_Buffer_InputPraise_SideToWrite;
        }
        public bool GetState_Buffer_OutputPraise_SideToWrite()
        {
            return state_Buffer_OutputPraise_SideToWrite;
        }

        public Avril_FSD_ServerAssembly.Settings GetSettings()
        {
            return settings;
        }
        public List<Avril_FSD_ServerAssembly.Input> GetStack_InputPraise()
        {
            return stack_InputPraise;
        }
        public List<Avril_FSD_ServerAssembly.Output> GetStack_OutputsPraise()
        {
            return stack_OutputPraise;
        }

        public Avril_FSD_ServerAssembly.User_I GetUserI()
        {
            return user_I;
        }
    }
}
