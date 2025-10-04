// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include <array>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <thread>
#include <vector>
#include "include/LIB_LaunchEnableForConcurrentThreadsAt_SERVER/LaunchEnableForConcurrentThreadsAt_SERVER_Framework.h"
#include "include/LIB_WriteEnableForThreadsAt_SERVERINPUTACTION/WriteEnableForThreadsAt_SERVERINPUTACTION_Framework.h"
#include "include/LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE/WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE_Framework.h"
#include <Eigen/Dense>
#include "framework.h"
#include "Framework_Server.h"
#include "Server.h"
#include "Global.h"
#include "Algorithms.h"
#include "Concurrent.h"
#include "Concurrent_Control.h"
#include "Data.h"
#include "Data_Control.h"
#include "Input.h"
#include "Input_Control.h"
#include "User_I.h"
#include "Praise0_Input.h"
#include "Praise1_Input.h"
#include "Praise2_Input.h"
#include "Output.h"
#include "Output_Control.h"
#include "User_O.h"
#include "Praise0_Output.h"
#include "Praise1_Output.h"
#include "Praise2_Output.h"
#include "User_Alg.h"
#include "Praise0_Algorithm.h"
#include "Praise1_Algorithm.h"
#include "Praise2_Algorithm.h"
#include "Execute.h"
#include "include/LIB_LaunchEnableForConcurrentThreadsAt_SERVER/LIB_LaunchEnableForConcurrentThreadsAt_SERVER.h"
#include "include/LIB_WriteEnableForThreadsAt_SERVERINPUTACTION/LIB_WriteEnableForThreadsAt_SERVERINPUTACTION.h"
#include "include/LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE/LIB_WriteEnableForThreadsAt_SERVEROUTPUTRECIEVE.h"
#include "Execute_Control.h"
#include "GameInstance.h"
#include "Player.h"
#include "FirstPersonCamera.h"
#include "Settings.h"

#endif //PCH_H
