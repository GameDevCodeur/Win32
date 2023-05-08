// GAMEDEVCODEUR
// Creer fenetre avec win32 api
// -Wall
//

#include<windows.h>
#include "defines.h"

struct {
    HINSTANCE hInstance;
    HWND hwnd;
} typedef internal_state;

LRESULT CALLBACK WindowProcessMessage(HWND, UINT, WPARAM, LPARAM);

int main(void) 
{
    internal_state state = {0};
    state.hInstance      = GetModuleHandleA(NULL);
    
    WNDCLASS wc          = {0};
    wc.lpszClassName     = "Ma classe de fenetre";
    wc.lpfnWndProc       = WindowProcessMessage;
    wc.hInstance         = state.hInstance;
    
    if(!RegisterClass(&wc)) { return -1; }
    
    state.hwnd = CreateWindowA (
                                    "Ma classe de fenetre", 
                                    "Apprendre a programmer Windows", 
                                    WS_OVERLAPPEDWINDOW, 
                                    CW_USEDEFAULT, CW_USEDEFAULT,
                                    CW_USEDEFAULT, CW_USEDEFAULT, 
                                    (HWND)NULL, (HMENU)NULL, 
                                    state.hInstance, 
                                    (LPVOID)NULL
                               );
    
	if(state.hwnd == NULL) { return -1; }
       
    ShowWindow(state.hwnd, SW_SHOW);
        
    while(TRUE) 
	{
        MSG message;
        while(PeekMessageA(&message, NULL, 0, 0, PM_REMOVE)) 
		{
            TranslateMessage(&message);
            DispatchMessageA(&message);
        }    
        // Faites des trucs de jeu ici
    }
    
    return 0;
}

LRESULT CALLBACK WindowProcessMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
    switch(msg)
	{  
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    // Fournir un traitement par defaut aux autres messages.
    return DefWindowProcA(hwnd, msg, wParam, lParam);
}
