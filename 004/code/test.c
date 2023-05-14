
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
				i16 i = 0 ;
				for(;i<SURFACE.Width;++i)
					RenderDrawLine(0,0,i,30);
			}

			// Arrêt de la mesure du temps
			QueryPerformanceCounter(&liStop);
			
			LONGLONG llTimeDiff = liStop.QuadPart - liStart.QuadPart;
			
			// Pour obtenir la durée en millisecondes
			f64 dftDuration = (f64)llTimeDiff * 1000.0;
			dftDuration  /= (f64)Frequency.QuadPart;
			
			// Affichage
			printf("Time RenderDrawLine : %0.2f ms\n", dftDuration);

		}
	}
	
	void DrawLigneSlowBenchmark(void)
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
				i16 i = 0 ;
				for(;i<SURFACE.Width;++i)
					RenderDrawLineSlow(0,0,i,30);
			}

			// Arrêt de la mesure du temps
			QueryPerformanceCounter(&liStop);
			
			LONGLONG llTimeDiff = liStop.QuadPart - liStart.QuadPart;
			
			// Pour obtenir la durée en millisecondes
			f64 dftDuration = (f64)llTimeDiff * 1000.0;
			dftDuration  /= (f64)Frequency.QuadPart;
			
			// Affichage
			printf("Time RenderDrawLineSlow : %0.2f ms\n", dftDuration);
		  
		}
	}
	
#endif
