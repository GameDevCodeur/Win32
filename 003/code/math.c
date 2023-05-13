
#include "math.h"

u32 ARGBtoHex(u16 a, u16 r, u16 g, u16 b)
{   
	return (u32)(((a & 0xFF) << 24) + 
				 ((r & 0xFF) << 16) + 
				 ((g & 0xFF) << 8)  + (b & 0xff));
}

