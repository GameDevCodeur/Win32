
#pragma once

#include "../defines.h"

#define DRAW_SETPIXELXY(x, y, color) \
	*(u32*)((u32*)SURFACE.Memory+(y)*SURFACE.Width+(x))=(u32)color	

struct {
	u32 DrawColor;
} static RENDER;

void SetRenderDrawColor(u32 Color);
void RenderClear(void);
void RenderDrawPoint(u16 x, u16 y);
void RenderDrawLine(u16 x0, u16 y0, u16 x1, u16 y1);
void RenderPresent(HDC DeviceContext);
