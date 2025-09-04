/*
*  Managed C# wrapper for AVRIL Server library by Jasper Assembly Pty Ltd.
*  Copyright (c) 2022 - 2025 Brenton James Maddocks BEng(CompSys).  
*  All rights reserved.
*/
using System;
using System.Runtime.InteropServices;
using System.Security;

namespace Avril_FSD
{
    [SuppressUnmanagedCodeSecurity]
    public static class Library_For_Server_Assembly
    {
        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr Initialise_Server_Assembly();

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Get_Flag_isNewInputDataReady(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Get_flag_isNewOutputDataReady(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Get_Flag_IsStackLoaded_Server_InputAction(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Get_Flag_IsStackLoaded_Server_OutputRecieve(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool GetFlag_Avril_FSD_Initialised(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Pop_Stack_Output(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Push_Stack_InputPraises(IntPtr obj);

        //[DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        //public static extern void Set_Flag_isNewInputDataReady(bool value);

// Praise Event Id
        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern byte Get_PraiseEventId(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Set_PraiseEventId(IntPtr obj, sbyte value);
    }

// Praise 0 Data
    [SuppressUnmanagedCodeSecurity]
    internal static class Library_For_Praise_0_Events
    {
        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Get_Praise0_Input_IsPingActive(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Set_Praise0_Input_IsPingActive(IntPtr obj, bool value);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Get_Praise0_Output_IsPingActive(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Set_Praise0_Output_IsPingActive(IntPtr obj, bool value);
    }
// Praise 1 Data
    [SuppressUnmanagedCodeSecurity]
    internal static class Library_For_Praise_1_Events
    {
        // Praise 1 Data
        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern float Get_Praise1_Input_mouseDelta_X(IntPtr obj);
        
        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern float Get_Praise1_Input_mouseDelta_Y(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Set_Praise1_Output_mouseDelta_X(IntPtr obj, float value);
        
        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Set_Praise1_Output_mouseDelta_Y(IntPtr obj, float value);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern float[] Get_Praise1_Output_Player_Fowards(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern float[] Get_Praise1_Output_Player_Up(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern float[] Get_Praise1_Output_Player_Right(IntPtr obj);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Set_Praise1_Output_Player_Fowards(IntPtr obj, float[] value);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Set_Praise1_Output_Player_Up(IntPtr obj, float[] value);

        [DllImport("LIBServerAssembly.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Set_Praise1_Output_Player_Right(IntPtr obj, float[] value);

    }
    // Praise 2 Data
    [SuppressUnmanagedCodeSecurity]
    internal static class Library_For_Praise_2_Events
    {

    }

}