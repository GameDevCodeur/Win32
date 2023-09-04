/*	
	==================
	DrawLineBressenham
	==================
	
	Dessine une ligne en reliant deux points, algorithme Bressenham's.
	
	https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham
	https://wiki.labomedia.org/index.php/Algorithme_de_Bresenham.html
	https://www.youtube.com/watch?v=RGB-wlatStc
	https://publimath.univ-irem.fr/publimath.php?r=%22algorithme+de+trac%E9+de+segment+de+Bresenham%22
	https://blog.demofox.org/2015/01/17/bresenhams-drawing-algorithms/
	https ://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham#Algorithme_g%C3%A9n%C3%A9ral_optimis%C3%A9
	
	
	Algorithme développé par Jack E. Bresenham en mai 1962, 
	alors qu’il travaillait dans un laboratoire informatique d’IBM et cherchait à 
	piloter un traceur attaché à une console texte. 
	Il détermine quels sont les points d’un plan discret qui doivent être tracés 
	afin de former une approximation de segment de droite entre deux points donnés.
	
*/
 
void LineBressenham(i16 x0, i16 y0, const i16 x1, const i16 y1)
{
  const i16 dx = ABS16(x1 - x0), sx = x0 < x1 ? 1 : -1;
  const i16 dy = ABS16(y1 - y0), sy = y0 < y1 ? 1 : -1;
  i16 err = (dx > dy ? dx : -dy) >> 1, e2; 
 
  while(1){
	DRAW_SETPIXELXY(x0, y0, RENDER.DrawColor);
	if(x0 == x1 && y0 == y1) break;	e2 = err;
	if(e2 > -dx) {err -= dy, x0 += sx;}
	if(e2 <  dy) {err += dx, y0 += sy;}
  }
}
