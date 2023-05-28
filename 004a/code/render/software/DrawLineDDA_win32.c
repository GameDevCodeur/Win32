/*	
	DrawLineDDA
	===========
	Dessine une ligne en reliant deux points, algorithme DDA (Digital Differential Analyzer).
	
	https://www.youtube.com/watch?v=T02UevufoJo
	https://fr.wikipedia.org/wiki/Analyseur_diff%C3%A9rentiel_num%C3%A9rique
	https://www.angelfire.com/ma/tigarsadonald/info4453/Principale.html
	https://boowiki.info/algorithme-dda/
	http://www.iro.umontreal.ca/~dift3355/notes.2012/01_2D.pdf
	https://www.researchgate.net/publication/238767856_Une_acceleration_du_trace_de_droites
	
*/

void DrawLineDDA(i16 x0, i16 y0, i16 x1, i16 y1)
{	
	const i16 dx = x1 - x0;
	const i16 dy = y1 - y0;

    i16 steps = MAX(ABS(dx), ABS(dy));
    f32 xInc  = dx / (f32) steps;
    f32 yInc  = dy / (f32) steps;
    f32 x 	  = (f32)x0;
    f32 y 	  = (f32)y0;
	
	DRAW_SETPIXELXY(x0, y0, RENDER.DrawColor);
    
	i16 k = 0;	
    while (k++ < steps)
	{
        x += xInc; y += yInc;
        DRAW_SETPIXELXY(ROUND(i16,x), ROUND(i16,y), RENDER.DrawColor);
    }
}
