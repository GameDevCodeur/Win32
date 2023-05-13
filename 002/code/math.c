
#include "math.h"

u16	Clamp(u16 min, u16 val, u16 max) 
{
	if (val < min) return min;
	if (val > max) return max;
	return val;
}
