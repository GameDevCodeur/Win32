
#include "test.h"

#if GDC_PLATFORM_WINDOWS
	
	void DrawLigneBenchmark(void)
	{
		LARGE_INTEGER Frequency;
		
		if(!QueryPerformanceFrequency(&Frequency))
			MessageBoxA(NULL, "QueryPerformanceFrequency !", 
							  "Error!", MB_ICONERROR | MB_OK);
		else
		{			
			LARGE_INTEGER liStart;
			LARGE_INTEGER liStop;

			// Démarrage de la mesure du temps
			QueryPerformanceCounter(&liStart);

			// Traitement
			{	
				i16 x, y;
				const i16 left   = 20;
				const i16 top    = 20;
				const i16 right  = SURFACE.Width-20;				
				const i16 botton = SURFACE.Height-20;
				
				DrawLineBressenham(left,  top,    right, top);
				DrawLineBressenham(left,  botton, right, botton);
				DrawLineBressenham(left,  top,    left,  botton);
				DrawLineBressenham(right, top,    right, botton);
								
				for(x = top; x < right; x += 6)
				{
					DrawLineBressenham(x, top, right-x+left, botton);
				}
				
				for(y = top; y < botton; y += 6)
				{
					DrawLineBressenham(left, y, right, botton-y+top);
				}
			}

			// Arrêt de la mesure du temps
			QueryPerformanceCounter(&liStop);
			
			LONGLONG llTimeDiff = liStop.QuadPart - liStart.QuadPart;
			
			// Pour obtenir la durée en millisecondes
			f64 dftDuration = (f64)llTimeDiff * 1000.0;
			dftDuration    /= (f64)Frequency.QuadPart;
			
			// Affichage
			printf("Time DrawLineBressenham : %0.2f ms\n", dftDuration);
		}
	}
	
#endif
