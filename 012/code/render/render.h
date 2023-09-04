
#pragma once

#include "../defines.h"

#define DRAW_SETPIXELXY(x, y, color) \
	*(u32*)((u32*)SURFACE.Memory+(y)*SURFACE.Width+(x))=(u32)color	

struct {
	u32 DrawColor;
} static RENDER;

void GDC_SetRenderDrawColor(const u32 Color);
void GDC_RenderClear(void);
void GDC_RenderPresent(const HDC DeviceContext);
