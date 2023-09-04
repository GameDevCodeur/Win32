
static void 
RectangleBressenham(const i16 left, const i16 top, const i16 right, const i16 botton)
{
	LineBressenham(left,  top,    right, top);
	LineBressenham(left,  botton, right, botton);
	LineBressenham(left,  top,    left,  botton);
	LineBressenham(right, top,    right, botton);	
}

static void 
FillRectanglePixels(const i16 left, const i16 top, 
					const i16 right, const i16 botton, const u32 FillColor)
{
	i16 IndX, IndY;	
	for(IndY = top; IndY < botton; ++IndY){ 
		u32 *Pixel = (u32*)SURFACE.Memory + (u32)(SURFACE.Width * IndY + left);
		for(IndX = left; IndX < right; ++IndX){
			*Pixel++ = FillColor;
		}
	}
}

static void 
FillRectangleBressenham(const i16 left, const i16 top, 
						const i16 right, const i16 botton, const u32 FillColor)
{
	RectangleBressenham(left, top, right, botton);
	FillRectanglePixels(left+1, top+1, right, botton, FillColor);
}

static void 
GDC_FillRectangle(const i16 x, const i16 y, 
				  const i16 w, const i16 h, const u32 FillColor)
{
	FillRectangleBressenham(x, y, x + w-1, y + h-1, FillColor);
}
