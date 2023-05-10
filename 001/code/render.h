
#pragma once

#include "defines.h"

struct {
	u32 DrawColor;
} static RENDER;

void SetRenderDrawColor(u32 Color);
void RenderClear(void);
void RenderPresent(void);

