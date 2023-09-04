
void TriangleBressenham(const i16 x1, const i16 y1, 
						const i16 x2, const i16 y2,
						const i16 x3, const i16 y3)
{
	LineBressenham(x1, y1, x2, y2);
	LineBressenham(x2, y2, x3, y3);
	LineBressenham(x3, y3, x1, y1);	
}


