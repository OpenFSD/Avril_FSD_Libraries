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
    public static class Library_For_WriteEnable_Stack_Client_OutputRecieve
    {
        [DllImport("LIBWriteEnableStackClientOutputRecieve.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr Initialise_WriteEnable();

        [DllImport("LIBWriteEnableStackClientOutputRecieve.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Write_End(byte coreId);

        [DllImport("LIBWriteEnableStackClientOutputRecieve.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Write_Start(byte coreId);
    }
}