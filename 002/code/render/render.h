
#pragma once

#include "../defines.h"

struct {
	u32 DrawColor;
} static RENDER;

void SetRenderDrawColor(u32 Color);
void RenderClear(void);
void RenderDrawPoint(u16 x, u16 y, u32 color); // 002
void RenderPresent(HDC DeviceContext);

