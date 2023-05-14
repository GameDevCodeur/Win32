// ----------------------------------------------------------
// Une surface peut être considérée comme un tableau 2D 
// où chaque élément contient une valeur de couleur 
// représentant une petite section de l’image, appelée pixel

#pragma once

#include "defines.h"

#define SURFACEMAXWIDTH 2500
#define SURFACEMAXHEIGHT 1600

struct {
	void* Memory;	// Byte order: BB GG RR AA, 0xAARRGGBB
	u16   Width;
	u16   Height;
} static SURFACE;

void CreateRGBSurface(void);
void ResizeRGBSurface(u16 Width, u16 Height);
void VirtualAllocSurface(u16 Width, u16 Height);
void FreeSurface(void);
void SetSizeSurface(void);
