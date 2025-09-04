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
    public static class Library_For_Concurrent_END
    {
        [DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Initialise_ConcurrentQue@ConcurrentQue_END_Library@Avril_FSD@@SAPAXXZ")]
        public static extern IntPtr Initialise_ConcurrentQue();

		[DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Request_Wait_Launch@ConcurrentQue_END_Library@Avril_FSD@@SAXPAVConcurrentQue_END_Framework@2@E@Z")]
		public static extern void Request_Wait_Launch(IntPtr obj, byte concurrent_CoreId);

		[DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Thread_End@ConcurrentQue_END_Library@Avril_FSD@@SAXPAVConcurrentQue_END_Framework@2@E@Z")]
		public static extern void Thread_End(IntPtr obj, byte concurrent_CoreId);

		[DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Get_coreId_To_Launch@ConcurrentQue_END_Library@Avril_FSD@@SADPAVConcurrentQue_END_Framework@2@@Z")]
		public static extern byte Get_coreId_To_Launch(IntPtr obj);

		[DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Get_Flag_Active@ConcurrentQue_END_Library@Avril_FSD@@SA_NPAVConcurrentQue_END_Framework@2@@Z")]
		public static extern bool Get_Flag_Active(IntPtr obj);

		[DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Get_Flag_ConcurrentCoreState@ConcurrentQue_END_Library@Avril_FSD@@SA_NPAVConcurrentQue_END_Framework@2@E@Z")]
		public static extern bool Get_Flag_ConcurrentCoreState(IntPtr obj, byte concurrent_CoreId);

		[DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Get_Flag_Idle@ConcurrentQue_END_Library@Avril_FSD@@SA_NPAVConcurrentQue_END_Framework@2@@Z")]
		public static extern bool Get_Flag_Idle(IntPtr obj);

		[DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Get_State_LaunchBit@ConcurrentQue_END_Library@Avril_FSD@@SA_NPAVConcurrentQue_END_Framework@2@@Z")]
		public static extern bool Get_State_LaunchBit(IntPtr obj);

		[DllImport("LIBLaunchEnableForConcurrentThreadsAtEND.dll", EntryPoint = "?Set_state_ConcurrentCore@ConcurrentQue_END_Library@Avril_FSD@@SAXPAVConcurrentQue_END_Framework@2@E_N@Z")]
		public static extern void Set_State_ConcurrentCoreState(IntPtr obj, byte concurrent_CoreId, bool value);
	}
}