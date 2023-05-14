/*	
	Comment Accélérer ?
	=====================
	Alors, que voyons-nous dans ce code ? Il y a:
	Une boucle
	Des valeurs entières
	Des valeurs en virgule flottante
	Des calculs sur ces valeurs: additions, soustractions, multiplications, et divisions
	Un appel à la fonction DRAW_SETPIXELXY

	Supprimer la multiplication
	===========================
	Regardez la formule à l'intérieur de la boucle:	f32 y = slope * (x - x0) + y0;
	Comment y change quand x va de x0 à x1 ?
	Au début, quand x = x0, (x - x0) s'annule et y démarre à y0.
	Ensuite, à chaque fois que x augmente de 1, y est augmenté de la pente (slope).

*/
void RenderDrawLine(i16 x0, i16 y0, i16 x1, i16 y1)
{	
	f32 slope = (f32)(y1 - y0) / (f32)(x1 - x0); 
	f32 y = (f32)y0;
	i16 x = x0;
	for (;x <= x1; ++x)
	{
		//f32 y = slope * (x - x0) + y0;		
		DRAW_SETPIXELXY(x, (i16)y, RENDER.DrawColor);
		//C'est une grande amélioration. 
		//Il y a beaucoup moins de calculs à l'intérieur de la boucle.
		//Il ne reste qu'une addition !
		y += slope;
	}
}

void RenderDrawLineSlow(i16 x0, i16 y0, i16 x1, i16 y1)
{	
	f32 slope = (f32)(y1 - y0) / (f32)(x1 - x0);
	i16 x=x0;
	for (;x<=x1;++x)
	{
		f32 y = slope * (x - x0) + y0;
		DRAW_SETPIXELXY(x, (i16)y, RENDER.DrawColor);
	}
}

