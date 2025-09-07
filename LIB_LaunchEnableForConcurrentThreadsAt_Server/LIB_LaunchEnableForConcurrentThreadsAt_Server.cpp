// LIB_LaunchEnableForConcurrentThreadsAt_SERVER.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_LaunchEnableForConcurrentThreadsAt_SERVER.h"


// This is an example of an exported variable
LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API int nLIBLaunchEnableForConcurrentThreadsAtSERVER=0;

// This is an example of an exported function.
LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API int fnLIBLaunchEnableForConcurrentThreadsAtSERVER(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CLIBLaunchEnableForConcurrentThreadsAtSERVER::CLIBLaunchEnableForConcurrentThreadsAtSERVER()
{
    return;
}
