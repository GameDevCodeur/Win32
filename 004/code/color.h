
#pragma once

#include "defines.h"

#define GETALPHAARGBCOLOR(c)(((c)&0xFF000000)>>(8*3))
#define GETREDARGBCOLOR(c)  (((c)&0x00FF0000)>>(8*2))
#define GETGREENARGBCOLOR(c)(((c)&0x0000FF00)>>(8*1))
#define GETBLUEARGBCOLOR(c) (((c)&0x000000FF)>>(8*0))

#define WHITEARGBCOLOR 	0xFFAAAAAA
#define REDARGBCOLOR	0xFFAA2020
#define GREENARGBCOLOR	0xFF20AA20
#define BLUEARGBCOLOR	0xFF2020AA

#define ARGB(a,r,g,b)((((a)&0xFF)<<(8*0))|(((r)&0xFF)<<(8*1))| \
                      (((g)&0xFF)<<(8*2))|(((b)&0xFF)<<(8*3)))

