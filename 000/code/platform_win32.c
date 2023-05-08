
#include "platform.h"

#if GDC_PLATFORM_WINDOWS

	#define WIN32_LEAN_AND_MEAN 1

	#include <windows.h>

	struct {
		HINSTANCE hInstance;
		HWND hwnd;	
	} state;

	b8 running;

	LRESULT CALLBACK WindowProcessMessage(HWND, UINT, WPARAM, LPARAM);

	b8 platform_system_startup(	const char * application_name,
								i32 x, i32 y, i32 width, i32 height)
	{	
		state.hInstance     = GetModuleHandleA(NULL);
		running 			= TRUE;
		
		WNDCLASS wc         = {0};
		wc.lpszClassName    = "Ma classe de fenetre";
		wc.lpfnWndProc      = WindowProcessMessage;
		wc.hInstance        = state.hInstance;
		
		if(!RegisterClass(&wc)) { return FALSE; }
		
		state.hwnd = CreateWindowA (
										"Ma classe de fenetre", 
										application_name, 
										WS_OVERLAPPEDWINDOW, 
										x, y, width, height, 
										(HWND)NULL, (HMENU)NULL, 
										state.hInstance, 
										(LPVOID)NULL
								   );
		
		if(state.hwnd == NULL) { return FALSE; }
		
		ShowWindow(state.hwnd, SW_SHOW);
		
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
			// Faites des trucs de jeu ici
		}
		
		return TRUE;
	}

	void platform_system_shutdown(void)
	{
		if (state.hwnd)
		{
			DestroyWindow(state.hwnd);
			state.hwnd = 0;
		}    
	}

	LRESULT CALLBACK WindowProcessMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
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
