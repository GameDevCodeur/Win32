
/*	
	x1 > x0               : x augmente.
	y1 > y0 			  : y augmente.
	(x1 - x0) > (y1 - y0) : la ligne est plus horizontale que verticale.
	
	La forme canonique (fonctionnelle) d'une droite est : y = a x + b , 
	où a est la pente de la droite et b est son ordonnée à l'origine (valeur initiale).
	y = a * x + b

	a est facile à comprendre. 
	C'est la pente de la droite (la quantité d'augmentation en y divisée par 
								 la quantité d'augmentation en x).

	Dans notre cas:	a = (y1 - y0) / (x1 - x0)
	
	Notre premier point (x0, y0) appartient à la droite, 
	donc il suit aussi l'équation:	y0 = a * x0 + b

	Maintenant si on soustrait cette équation à la précédente, 
	on obtient: y - y0 = a * (x - x0) + b - b
	
	Et b disparaît. 
	Donc après une petite réécriture, 
	on obtient une nouvelle formule pour notre ligne: y = a * (x - x0) + y0
	
*/
void RenderDrawLine(u16 x0, u16 y0, u16 x1, u16 y1)
{	
	f32 slope = (f32)(y1 - y0) / (f32)(x1 - x0);
	u16 x;
	for (x = x0; x <= x1; ++x)
	{
		f32 y = slope * (x - x0) + y0;
		DRAW_SETPIXELXY(x, (u16)y, RENDER.DrawColor);
	}
}

