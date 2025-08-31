using System;

namespace Avril_FSD_ServerAssembly
{
    public class Praise1_Input
    {
        Int16 position_X;
        Int16 position_Y;

        public Praise1_Input()
        {
            position_X = 0;
            position_Y = 0;
        }

        public Int16 Get_Position_X() 
        {   
            return position_X; 
        }

        public Int16 Get_Position_Y()
        {
            return position_Y;
        }

        public void Set_Position_X(Int16 value) 
        {
            position_X = value;
        }
        
        public void Set_Position_Y(Int16 value)
        {
            position_Y = value;
        }
    }
}
