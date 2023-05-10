// ----------------------------------------------------------
// Une surface peut être considérée comme un tableau 2D 
// où chaque élément contient une valeur de couleur 
// représentant une petite section de l’image, appelée pixel

#pragma once

#include "defines.h"

//001
struct {
	void* Memory;	// Byte order: BB GG RR AA, 0xAARRGGBB
	u16   Width;
	u16   Height;
} static SURFACE;

static BITMAPINFO BitmapInfo;

static u16 ClientWidth;
static u16 ClientHeight;

b8 CreateRGBSurface(void);
void FreeSurface(void);
