
#include "surface.h"

#if GDC_PLATFORM_WINDOWS

	static BITMAPINFO BitmapInfo;
	
	static void SetBitmapInfo(void)
	{
		// Structure BitmapInfo pour StretchDIBits
		BitmapInfo.bmiHeader.biSize 		= sizeof(BitmapInfo.bmiHeader);
		BitmapInfo.bmiHeader.biWidth 		= SURFACE.Width;
		BitmapInfo.bmiHeader.biHeight 		= -SURFACE.Height;
		BitmapInfo.bmiHeader.biPlanes 		= 1;
		BitmapInfo.bmiHeader.biBitCount 	= 32;
		BitmapInfo.bmiHeader.biCompression 	= BI_RGB;
	}
	
	void VirtualAllocSurface(i16 Width, i16 Height)
	{	
		// Surface Width et Height minimum MIN..MAX px. 
		SURFACE.Width  = CLAMP(SURFACEMINWIDTH,  Width,  SURFACEMAXWIDTH);
		SURFACE.Height = CLAMP(SURFACEMINHEIGHT, Height, SURFACEMAXHEIGHT);
	
		// Caluler Memoire a allouer
		u16 BytesPerPixel = 4;
		u32 MemorySize = (u32)(SURFACE.Width * SURFACE.Height * BytesPerPixel);

		// Liberer la surface
		FreeSurface();
		
		// Allouer la memoire
		SURFACE.Memory = VirtualAlloc(	0,
										MemorySize,
										MEM_RESERVE|MEM_COMMIT,
										PAGE_READWRITE);
		
		if(SURFACE.Memory == NULL)
		{ 
			MessageBoxA(NULL, "Impossible d'allouer la sueface !", 
						"Error!", MB_ICONERROR | MB_OK);
		}
	}
	
	void ResizeRGBSurface(i16 Width, i16 Height)
	{		
		VirtualAllocSurface(Width, Height);
		SetBitmapInfo();
	}
	
	void CreateRGBSurface(void)
	{
		SetSizeSurface();		
		ResizeRGBSurface(SURFACE.Width, SURFACE.Height);
	}
	
	void SetSizeSurface(void)
	{
		RECT clientRect;
		GetClientRect(STATE.hwnd, &clientRect);
		SURFACE.Width  = (i16)(clientRect.right - clientRect.left);
		SURFACE.Height = (i16)(clientRect.bottom - clientRect.top);
	}
	
	void FreeSurface(void)
	{
		if(SURFACE.Memory)
			VirtualFree(SURFACE.Memory, 0, MEM_RELEASE);			
	}
	
#endif
