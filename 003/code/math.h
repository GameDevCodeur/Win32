
#pragma once

#include "defines.h"

#define MIN(a,b)((a)<(b)?(a):(b))
#define MAX(a,b)((a)>(b)?(a):(b))

#define CLAMP(min,val,max)((val)>(max)?(max):((val)<(min)?(min):(val)))

u32 ARGBtoHex(u16 a, u16 r, u16 g, u16 b);
