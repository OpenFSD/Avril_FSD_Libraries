// LIB_LaunchEnableForConcurrentThreadsAt_Server.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "LIB_LaunchEnableForConcurrentThreadsAt_Server.h"


// This is an example of an exported variable
LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API int nLIBLaunchEnableForConcurrentThreadsAtServer=0;

// This is an example of an exported function.
LIBLAUNCHENABLEFORCONCURRENTTHREADSATSERVER_API int fnLIBLaunchEnableForConcurrentThreadsAtServer(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CLIBLaunchEnableForConcurrentThreadsAtServer::CLIBLaunchEnableForConcurrentThreadsAtServer()
{
    return;
}
