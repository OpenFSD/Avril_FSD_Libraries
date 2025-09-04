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
    public static class Library_For_WriteEnable_STACK
    {
        [DllImport("LIBWriteEnableForThreadsAtSTACK.dll", EntryPoint = "?Initialise_WriteEnable@WriteEnableForThreadsAt_STACK_Library@Avril_FSD@@SAPAXXZ")]
        public static extern IntPtr Initialise_WriteEnable();

        [DllImport("LIBWriteEnableForThreadsAtSTACK.dll", EntryPoint = "?Write_End@WriteEnableForThreadsAt_STACK_Library@Avril_FSD@@QAEXPAVWriteEnable_STACK_Framework@2@E@Z")]
        public static extern void Write_End(IntPtr obj, byte coreId);

        [DllImport("LIBWriteEnableForThreadsAtSTACK.dll", EntryPoint = "?Write_Start@WriteEnableForThreadsAt_STACK_Library@Avril_FSD@@QAEXPAVWriteEnable_STACK_Framework@2@E@Z")]
        public static extern void Write_Start(IntPtr obj, byte coreId);
    }
}