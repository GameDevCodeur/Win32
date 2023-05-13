
#include "platform.h"

#if GDC_PLATFORM_WINDOWS

	#define WIN32_LEAN_AND_MEAN 1
	#include <windows.h>
	#include <stdio.h> // TODO(GDC): Debug printf
	
	#define WINDOW_FLAGS WS_VISIBLE|WS_OVERLAPPEDWINDOW

	struct {
		HINSTANCE hInstance;
		HWND hwnd;
	} static STATE;
		
	#include "../math.c"
	#include "../surface_win32.c"
	#include "../render/software/render_win32.c"
			
	static b8 running;

	LRESULT CALLBACK WindowProcessMessage(HWND, UINT, WPARAM, LPARAM);

	b8 platform_system_startup(	const char * application_name,
								u16 x, u16 y, u16 width, u16 height)
	{	
		STATE.hInstance     = GetModuleHandleA(NULL);
		running 			= TRUE;

		WNDCLASSA wc        = {0};
		wc.lpszClassName    = "Ma classe de fenetre";
		wc.lpfnWndProc      = WindowProcessMessage;
		wc.hInstance        = STATE.hInstance;
		wc.hCursor 			= LoadCursor(NULL, IDC_ARROW);
		
		if(!RegisterClassA(&wc))
		{
			MessageBoxA(NULL, "Impossible d'enregistrer la classe !", 
						"Error!", MB_ICONERROR | MB_OK);
			return FALSE;
		}
		
		STATE.hwnd = CreateWindowA( wc.lpszClassName, 
									application_name, 
									WINDOW_FLAGS, 
									x, y, width, height, 
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
		SetRenderDrawColor(0xFF0000FF); // ARGB
		
		while(running) 
		{
			MSG message;
			while(PeekMessageA(&message, NULL, 0, 0, PM_REMOVE)) 
			{
				TranslateMessage(&message);
				DispatchMessageA(&message);
			}
			
			// Logic du jeu
			
			// Rendu du jeu - 002
			HDC DeviceContext = GetDC(STATE.hwnd);
				RenderClear();
				RenderDrawPoint(5, 5, 0xFFFFFFFF);
				RenderPresent(DeviceContext);
			ReleaseDC(STATE.hwnd, DeviceContext);
		
			Sleep(60);
		}
		
		return TRUE;
	}

	void platform_system_shutdown(void)
	{
		FreeSurface();
		
		if (STATE.hwnd){
			DestroyWindow(STATE.hwnd);
			STATE.hwnd = 0;
		}
	}
	
	// 002
	void OnSize(HWND hwnd, u16 flag, u16 Width, u16 Height)
	{
		UNREFERENCED_PARAMETER(hwnd);
		UNREFERENCED_PARAMETER(flag);
		
		// TODO(GDC): Debug
		printf("Surface : %ux%u\n", Width, Height);
		
		ResizeRGBSurface(Width, Height);	
	}

	LRESULT CALLBACK WindowProcessMessage(	HWND hwnd, UINT msg, 
											WPARAM wParam, LPARAM lParam) 
	{
		switch(msg)
		{
			// 002
			case WM_SIZE:
			{
				u16 width  = LOWORD(lParam); // Macro pour obtenir le poids LO.
				u16 height = HIWORD(lParam); // Macro pour obtenir le poids HI.

				// Repondre au message :
				OnSize(hwnd, (u16)wParam, width, height);
				
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
