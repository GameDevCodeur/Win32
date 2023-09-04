
#include "platform.h"

#if GDC_PLATFORM_WINDOWS

	#define WIN32_LEAN_AND_MEAN 1
	
	#include <windows.h>
	#include <stdio.h> 		// for printf
	
	#define WINDOW_FLAGS WS_VISIBLE|WS_OVERLAPPEDWINDOW
	#define	WINDOW_CLASS_NAME "Ma classe de fenetre"

	struct { HINSTANCE hInstance; HWND hwnd; } static STATE;
	
	#include "../math.c"
	#include "../color.c"
		
	#include "../surface/surface_win32.c"
	#include "../render/software/render_win32.c"
	
	#include "../game.c"
	
	static b8 running;

	LRESULT CALLBACK WindowProcessMessage(HWND, UINT, WPARAM, LPARAM);

	b8 platform_system_startup(	const char * application_name,
								i16 x, i16 y, i16 width, i16 height) {	
		i16 client_x      = x;
		i16 client_y      = y;
		i16 client_width  = width;
		i16 client_height = height;
		
		i16 window_x      = client_x;
		i16 window_y      = client_y;
		i16 window_width  = client_width;
		i16 window_height = client_height;		
		
		STATE.hInstance     = GetModuleHandleA(NULL);
		running 			= TRUE;

		WNDCLASSA wc        = {0};
		wc.lpszClassName    = WINDOW_CLASS_NAME;
		wc.lpfnWndProc      = WindowProcessMessage;
		wc.hInstance        = STATE.hInstance;
		wc.hCursor 			= LoadCursor(NULL, IDC_ARROW);
		
		if(!RegisterClassA(&wc))
		{
			MessageBoxA(NULL, "Impossible d'enregistrer la classe !", 
						"Error!", MB_ICONERROR | MB_OK);
			return FALSE;
		}
		
		{
			// Taille de la bordure.		
			RECT border_rect = {0, 0, 0, 0};
			AdjustWindowRectEx(&border_rect, WINDOW_FLAGS, 0, WS_EX_APPWINDOW);
			
			// Supprimer la bordure (+=) car les valeurs sont negatives
			window_x += border_rect.left;
			window_y += border_rect.top;
			
			// Agrandit la bordure du systeme d'exploitation.
			window_width  += border_rect.right  - border_rect.left;
			window_height += border_rect.bottom - border_rect.top;
		}
		
		// Creation de la fenetre
		STATE.hwnd = CreateWindowExA(	WS_EX_APPWINDOW, 
										wc.lpszClassName,
										application_name,
										WINDOW_FLAGS, 	
										window_x, window_y, 
										window_width, window_height,
										(HWND)NULL, (HMENU)NULL,  
										0, (LPVOID)NULL);
		
		if(STATE.hwnd == NULL)
		{ 
			MessageBoxA(NULL, "Impossible de creer la fenetre !", 
						"Error!", MB_ICONERROR | MB_OK);
			return FALSE;
		}
		
		return TRUE;
	}
	
	b8 platform_pump_messages(void)
	{	
		// Initilisation du jeu
		GDC_Init();
		
		while(running) 
		{	
			MSG message;
			while(PeekMessageA(&message, NULL, 0, 0, PM_REMOVE)) 
			{
				TranslateMessage(&message);
				DispatchMessageA(&message);
			}

			// Logic du jeu
			GDC_Update();

			// Rendu du jeu			
			HDC DeviceContext = GetDC(STATE.hwnd);								
			GDC_Draw();
			GDC_RenderPresent(DeviceContext);
			ReleaseDC(STATE.hwnd, DeviceContext);
		}		
		return TRUE;
	}

	void platform_system_shutdown(void)	{
		FreeSurface();
		
		if (STATE.hwnd)
		{
			DestroyWindow(STATE.hwnd);
			STATE.hwnd = 0;
		}
	}

	void OnSize(HWND hwnd, u16 flag, i16 Width, i16 Height)	{
		UNREFERENCED_PARAMETER(hwnd);
		UNREFERENCED_PARAMETER(flag);
		
		// TODO(GDC): Debug
		printf("Surface : %ux%u\n", SURFACE.Width, SURFACE.Height);
		printf("Surface : %ux%u\n", Width, Height);
			
		ResizeRGBSurface(Width, Height);
	}

	LRESULT CALLBACK WindowProcessMessage(	HWND hwnd, UINT msg, 
											WPARAM wParam, LPARAM lParam) {
		switch(msg)
		{
			case WM_SIZE:
			{
				if(wParam != SIZE_MINIMIZED){
					i16 Width  = (i16)LOWORD(lParam); // Macro pour obtenir le poids LO.
					i16 Height = (i16)HIWORD(lParam); // Macro pour obtenir le poids HI.				
					OnSize(hwnd, (u16)wParam, Width, Height);
				}
				
			} break;
			
			case WM_CLOSE:				
				running = FALSE;				
				return 0;
				
			case WM_DESTROY:				
				PostQuitMessage(0);
				return 0;
		}
		
		// Fournir un traitement par defaut aux autres messages.
		return DefWindowProcA(hwnd, msg, wParam, lParam);
	}

#endif  // GDC_PLATFORM_WINDOWS
