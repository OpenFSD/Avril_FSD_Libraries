using System;
using System.Collections.Generic;

namespace Avril_FSD_ServerAssembly
{
    public class Data
    {
        static private Avril_FSD_ServerAssembly.Data_Control _data_Control = null;

        static private Avril_FSD_ServerAssembly.Game_Instance _gameInstance = null;
        static private Avril_FSD_ServerAssembly.Settings _settings = null;
        static private Avril_FSD_ServerAssembly.Input_Instance _input_Instnace = null;
        static private Avril_FSD_ServerAssembly.Output_Instance _output_Instnace = null;
        static private List<Avril_FSD_ServerAssembly.Input> _stack_InputPraise = null;
        static private List<Avril_FSD_ServerAssembly.Output> _stack_OutputPraise = null;
        static private Avril_FSD_ServerAssembly.User_I _user_I = null;
        static private Avril_FSD_ServerAssembly.User_O _user_O = null;

        bool _state_Buffer_InputPraise_SideToWrite;
        bool _state_Buffer_OutputPraise_SideToWrite;

        public Data()
        {
            Set_data_Control(null);

            Set_gameInstance(new Avril_FSD_ServerAssembly.Game_Instance());
            while (Get_gameInstance() == null) { }

            Set_settings(new Avril_FSD_ServerAssembly.Settings());
            while (Get_settings() == null) { }

            Set_input_Instnace(new Avril_FSD_ServerAssembly.Input_Instance());
            while (Get_input_Instnace() == null) { }

            Set_output_Instnace(new Avril_FSD_ServerAssembly.Output_Instance());
            while (Get_output_Instnace() == null) { }

            Set_user_I(new Avril_FSD_ServerAssembly.User_I());
            while (_user_I == null) { }

            Set_user_O(new Avril_FSD_ServerAssembly.User_O());
            while (_user_O == null) { }

            Set_state_Buffer_InputPraise_SideToWrite(true);
            Set_state_Buffer_OutputPraise_SideToWrite(false);
         
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
            Set_data_Control(new Avril_FSD_ServerAssembly.Data_Control());
            while (Get_data_Control() == null) { }
        }

        public void Flip_InBufferToWrite()
        {
            _state_Buffer_InputPraise_SideToWrite = !_state_Buffer_InputPraise_SideToWrite;
        }
        public void Flip_OutBufferToWrite()
        {
            _state_Buffer_OutputPraise_SideToWrite = !_state_Buffer_OutputPraise_SideToWrite;
        }

        public Avril_FSD_ServerAssembly.Data_Control Get_data_Control()
        {
            return _data_Control;
        }
        public Avril_FSD_ServerAssembly.Game_Instance Get_gameInstance()
        {
            return _gameInstance;
        }
        public Avril_FSD_ServerAssembly.Settings Get_settings()
        {
            return _settings;
        }
        public Avril_FSD_ServerAssembly.Input_Instance Get_input_Instnace()
        {
            return _input_Instnace;
        }
        public Avril_FSD_ServerAssembly.Output_Instance Get_output_Instnace()
        {
            return _output_Instnace;
        }
        public List<Avril_FSD_ServerAssembly.Input> Get_stack_InputPraise()
        {
            return _stack_InputPraise;
        }
        public List<Avril_FSD_ServerAssembly.Output> Get_stack_OutputPraise()
        {
            return _stack_OutputPraise;
        }
        public Avril_FSD_ServerAssembly.User_I Get_user_I()
        {
            return _user_I;
        }
        public Avril_FSD_ServerAssembly.User_O Get_user_O()
        {
            return _user_O;
        }
        public bool Get_state_Buffer_InputPraise_SideToWrite()
        {
            return _state_Buffer_InputPraise_SideToWrite;
        }
        public bool Get_state_Buffer_OutputPraise_SideToWrite()
        { 
            return _state_Buffer_OutputPraise_SideToWrite;
        }
        private void Set_data_Control(Avril_FSD_ServerAssembly.Data_Control dataControl)
        {
            _data_Control = dataControl;
        }

        private void Set_gameInstance(Avril_FSD_ServerAssembly.Game_Instance gameInstance)
        {
            _gameInstance = gameInstance;
        }
        private void Set_settings(Avril_FSD_ServerAssembly.Settings settings)
        {
            _settings = settings;
        }
        private void Set_input_Instnace(Avril_FSD_ServerAssembly.Input_Instance inputInstance)
        {
            _input_Instnace = inputInstance;
        }
        private void Set_output_Instnace(Avril_FSD_ServerAssembly.Output_Instance outputInstance)
        {
            _output_Instnace = outputInstance;
        }
        private void Set_stack_InputPraise(List<Avril_FSD_ServerAssembly.Input> stack)
        {
            _stack_InputPraise = stack;
        }
        private void Set_stack_OutputPraise(List<Avril_FSD_ServerAssembly.Output> stack)
        {
            _stack_OutputPraise = stack;
        }
        private void Set_user_I(Avril_FSD_ServerAssembly.User_I userInputs)
        {
            _user_I = userInputs;
        }
        private void Set_user_O(Avril_FSD_ServerAssembly.User_O userOutputs)
        {
            _user_O = userOutputs;
        }
        private void Set_state_Buffer_InputPraise_SideToWrite(bool value)
        {
            _state_Buffer_InputPraise_SideToWrite = value;
        }
        private void Set_state_Buffer_OutputPraise_SideToWrite(bool value)
        {
            _state_Buffer_OutputPraise_SideToWrite = value;
        }
    }
}
