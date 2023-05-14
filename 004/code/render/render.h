
#pragma once

#include "../defines.h"

#define DRAW_SETPIXELXY(x, y, color) \
	*(u32*)((u32*)SURFACE.Memory+(y)*SURFACE.Width+(x))=(u32)color	

struct {
	u32 DrawColor;
} static RENDER;

void SetRenderDrawColor(u32 Color);
void RenderClear(void);
void RenderDrawPoint(i16 x, i16 y);
void RenderDrawLine(i16 x0, i16 y0, i16 x1, i16 y1);
void RenderPresent(HDC DeviceContext);
