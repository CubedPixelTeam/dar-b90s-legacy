#include <PA9.h>
#include "all_gfx.h"
#include "HowToPlay.h"
#include "MainMenu.h"

int HowToPlay(void){
	s8 i = 0;
	int text_y = 0;
	float y = 0;
	PA_SetBrightness(0, -31);
	PA_SetBrightness(1, -31);
	
	FAT_LoadBackground(1,3,"data/bgs/mainbg/chess_partners");
	FAT_LoadBackground(1,2,"data/bgs/mainbg/howtoplay/help");
	FAT_LoadBackground(0,3,"data/bgs/mainbg/black_chess");
	FAT_LoadBackground(0,2,"data/bgs/mainbg/howtoplay/controls");
	
	FAT_LoadSprite(1,"nitro:/data/bgs/mainbg/howtoplay/scroll_Sprite","nitro:/data/bgs/mainbg/howtoplay/scroll_Pal");
	PA_LoadSpritePal(0,1,PaletteCustom);
	PA_CreateSprite(0,1,(void*)SpriteCustom[1],OBJ_SIZE_16X32,1,1,32,32);
	for (i = -31; i <= 0; i++) {
		if(Pad.Held.Down) text_y += Pad.Held.Down + 1;
		else if(Pad.Held.Up) text_y -= Pad.Held.Up + 1;

		if(text_y < 0) text_y = 0;
		else if (text_y > 310) text_y = 310;
		y += 0.5;
		PA_EasyBgScrollXY(1,2,0,text_y);		
		PA_EasyBgScrollXY(1,3,y,y);
		PA_EasyBgScrollXY(0,3,y,y);
		PA_SetBrightness(0, i);
		PA_SetBrightness(1, i);
		PA_WaitForVBL(); 
	}
	while(1){
		if(Pad.Held.Down) text_y += Pad.Held.Down + 1;
		else if(Pad.Held.Up) text_y -= Pad.Held.Up + 1;
		if(Pad.Newpress.B) {
			for (i = 0; i >= -31; i--) {
				PA_SetBrightness(0, i);
				PA_SetBrightness(1, i);
				PA_WaitForVBL(); 
			}	
			PA_ResetBgSys();
			MainMenu();
			return 0;
		}
		if(text_y < 0) text_y = 0;
		else if (text_y > 310) text_y = 310;
		y += 0.5;
		PA_EasyBgScrollXY(1,2,0,text_y);		
		PA_EasyBgScrollXY(1,3,y,y);
		PA_EasyBgScrollXY(0,3,y,y);
		PA_WaitForVBL();
	}
	return 0;
}