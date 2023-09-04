
#include "game.h"

static player Player = {0};

#if GDC_PLATFORM_WINDOWS

	void GDC_Init(void) {
		Player.x  = 10;
		Player.y  = 10;
		Player.w  = 32;
		Player.h  = 32;
		Player.vx = 1;
	}
	
	void GDC_Update(void) {	
		Player.x += Player.vx;
		if(Player.x > SURFACE.Width) Player.x = 0;
	}	
	
	void GDC_Draw(void) {
		GDC_SetRenderDrawColor(BLUEARGB); GDC_RenderClear();
		GDC_SetRenderDrawColor(WHITEARGB); 
		GDC_FillRectangle(Player.x, Player.y, Player.w, Player.h, FORESTGREENARGB);		
		printf("PX : %i \n", Player.x);
	}

#endif
