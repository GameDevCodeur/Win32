// ----------------------------------------------------------
// Une surface peut être considérée comme un tableau 2D 
// où chaque élément contient une valeur de couleur 
// représentant une petite section de l’image, appelée pixel

#pragma once

#include "../defines.h"

#define SURFACEMINWIDTH  32
#define SURFACEMINHEIGHT 32
#define SURFACEMAXWIDTH  2500
#define SURFACEMAXHEIGHT 1600

struct {
	i16   Width;
	i16   Height;
	void* Memory;	// Byte order: BB GG RR AA, 0xAARRGGBB	
} static SURFACE = {0};

void CreateRGBSurface(void);
void ResizeRGBSurface(i16 Width, i16 Height);
void VirtualAllocSurface(i16 Width, i16 Height);
void FreeSurface(void);
void SetSizeSurface(void);
