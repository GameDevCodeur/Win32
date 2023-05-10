
#include "surface.h"

#if GDC_PLATFORM_WINDOWS

	b8 CreateRGBSurface (void)
	{
		// Obtenir les dimensions de l'espace client   
		RECT ClientRect;
		GetClientRect(STATE.hwnd, &ClientRect);
		ClientWidth  = (u16)(ClientRect.right - ClientRect.left);
		ClientHeight = (u16)(ClientRect.bottom - ClientRect.top);
		
		SURFACE.Width  = ClientWidth;
		SURFACE.Height = ClientHeight;
		
		// Alloue de la mémoire pour le bitmap   
		u16 BytesPerPixel = 4;
		
		SURFACE.Memory = VirtualAlloc(0,
					SURFACE.Width * SURFACE.Height * BytesPerPixel,
					MEM_RESERVE|MEM_COMMIT,
					PAGE_READWRITE
		);
		
		if(SURFACE.Memory == NULL)
		{ 
			MessageBoxA(NULL, 
						"Impossible d'allouer la sueface !", 
						"Error!", MB_ICONERROR | MB_OK);
			return FALSE;
		}
		
		// Structure BitmapInfo pour StretchDIBits
		BitmapInfo.bmiHeader.biSize 		= sizeof(BitmapInfo.bmiHeader);
		BitmapInfo.bmiHeader.biWidth 		= SURFACE.Width;
		BitmapInfo.bmiHeader.biHeight 		= -SURFACE.Height;
		BitmapInfo.bmiHeader.biPlanes 		= 1;
		BitmapInfo.bmiHeader.biBitCount 	= 32;
		BitmapInfo.bmiHeader.biCompression 	= BI_RGB;
		
		return TRUE;
	}
	
	void FreeSurface(void)
	{
		if(SURFACE.Memory)
		{
			VirtualFree(SURFACE.Memory, 0, MEM_RELEASE);			
		}
	}
	
#endif
