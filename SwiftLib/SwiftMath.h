#pragma once
#include <iostream>


#include <cmath>

#ifdef __SSE__
#include <xmmintrin.h>
#endif
#ifdef __SSE2__
#include <emmintrin.h>
#endif

#ifdef __linux__
#include <cassert>
#include <float.h> // for FLT_MIN and FLT_MAX #3867
#endif

#ifdef MACOS_X
#ifdef __ppc__
// for square root estimate instruction
#include <ppc_intrinsics.h>
#endif
// for FLT_MIN
#include <float.h>
#endif

class SwiftMath
{
public:
	static void RSQ(float x); //recipical sq root.
};

