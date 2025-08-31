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
    public static class Library_For_Concurrent_Que_On_Client
    {
        [DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr Initialise_ConcurrentQue();

		[DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Request_Wait_Launch(byte concurrent_CoreId);

		[DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Thread_End(byte concurrent_CoreId);

		[DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern byte Get_coreId_To_Launch();

		[DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern bool Get_Flag_Active();

		[DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern bool Get_Flag_ConcurrentCoreState(byte concurrent_CoreId);

		[DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern bool Get_Flag_Idle();

		[DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern bool Get_State_LaunchBit();

		[DllImport("LIBConcurrentQueClient.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void SetFlag_ConcurrentCoreState(byte concurrent_CoreId, bool value);
	}
}