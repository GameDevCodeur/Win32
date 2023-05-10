
#include "platform.h"

#if GDC_PLATFORM_WINDOWS

	#define WIN32_LEAN_AND_MEAN 1
	#include <windows.h>	

	struct {
		HINSTANCE hInstance;
		HWND hwnd;
	} static STATE;
	
	//001
	#include "surface_win32.c"
	#include "render_win32.c"
			
	static b8 running;

	LRESULT CALLBACK WindowProcessMessage(HWND, UINT, WPARAM, LPARAM);

	b8 platform_system_startup(	const char * application_name,
								u32 x, u32 y, u32 width, u32 height)
	{	
		STATE.hInstance     = GetModuleHandleA(NULL);
		running 			= TRUE;

		WNDCLASSA wc        = {0};
		wc.lpszClassName    = "Ma classe de fenetre";
		wc.lpfnWndProc      = WindowProcessMessage;
		wc.hInstance        = STATE.hInstance;
		// 001
		wc.hCursor 			= LoadCursor(NULL, IDC_ARROW);
		
		if(!RegisterClassA(&wc)) {
			MessageBoxA(NULL, 
						"Impossible d'enregistrer la classe !", 
						"Error!", MB_ICONERROR | MB_OK);
			return FALSE;
		}
		
		STATE.hwnd = CreateWindowA (
										wc.lpszClassName, 
										application_name, 
										WS_OVERLAPPEDWINDOW|WS_VISIBLE, 
										x, y, width, height, 
										(HWND)NULL, (HMENU)NULL, 
										STATE.hInstance, 
										(LPVOID)NULL
								   );
		
		if(STATE.hwnd == NULL) { 
			MessageBoxA(NULL, 
						"Impossible de creer la fenetre !", 
						"Error!", MB_ICONERROR | MB_OK);
			return FALSE;
		}
		
		// 001		
		if(!CreateRGBSurface())
		{
			MessageBoxA(NULL, 
						"Impossible de creer la surface !", 
						"Error!", MB_ICONERROR | MB_OK);
			return FALSE;
		}
		
		return TRUE;
	}

	b8 platform_pump_messages(void)
	{
		while(running) 
		{
			MSG message;
			while(PeekMessageA(&message, NULL, 0, 0, PM_REMOVE)) 
			{
				TranslateMessage(&message);
				DispatchMessageA(&message);
			}
			
			// 001
			SetRenderDrawColor(0xFF0000FF); // ARGB
			RenderClear();
			RenderPresent();

			Sleep(1);
		}
		
		return TRUE;
	}

	void platform_system_shutdown(void)
	{
		// 001
		FreeSurface();

		if (STATE.hwnd){
			DestroyWindow(STATE.hwnd);
			STATE.hwnd = 0;
		}
	}

	LRESULT CALLBACK WindowProcessMessage(	HWND hwnd, UINT msg, 
											WPARAM wParam, LPARAM lParam) 
	{
		switch(msg)
		{  
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
