#include <PA9.h>
#include "zones/MainMenu.h"
#include "all_gfx.h"
#include "zones/HowToPlay.h"
#include "zones/stages/player.h"
#include "zones/stages/P1.h"

int MainMenu(void){
	s8 i = 0;
	FAT_LoadBackground(1,3,"nitro:/data/titlescreen/background/TitleScreen");
	FAT_LoadBackground(0,3,"nitro:/data/bgs/level_entry");
	FAT_LoadSprite(1,"nitro:/data/titlescreen/sprites/darTitle_Sprite.bin","nitro:/data/titlescreen/sprites/darTitle_Pal.bin");
	PA_LoadSpritePal(1,1,PaletteCustom);
	PA_CreateSprite(1,1,(void*)SpriteCustom[1],OBJ_SIZE_16X32,1,1,0,-71);
	PA_SetSpriteDblsize(1,1,1);
	PA_SetSpriteRotEnable(1,1,1);
	PA_SetRotsetNoAngle(1,1,128,128);
	for (i = -31; i <= 0; i++) {
		PA_SetBrightness(1, i);
		PA_WaitForVBL(); 
	}
	PA_InitText(0,0);
	for(i = -71;i<93;i+= 2){
		PA_SetSpriteXY(1,1,0,i);
		PA_WaitForVBL();
	}
	PA_StartSpriteAnim(1,1,1,1,0);
	for(i = 0;i<10;i+= 1) PA_WaitForVBL();
	
	PA_StartSpriteAnim(1,1,2,3,3);

	PA_LoadSprite16cPal(0,0,(void*)NewGameButton_Pal);
	PA_CreateSprite(0,0,(void*)NewGameButton_Sprite,OBJ_SIZE_64X32,0,0,98,9);
	PA_LoadSprite16cPal(0,2,(void*)HowToPlayButton_Pal);
	PA_CreateSprite(0,2,(void*)HowToPlayButton_Sprite,OBJ_SIZE_64X32,0,2,98,105);
	for (i = -31; i <= 0; i++) {
		PA_SetBrightness(0, i);
		PA_WaitForVBL(); 
		PA_WaitForVBL();
	}
	int y = 0;
	while(1){
		if(PA_SpriteTouched(0)){
			for (i = 0; i >= -31; i--) {
				PA_SetBrightness(0, i);
				PA_SetBrightness(1, i);
				PA_WaitForVBL(); 
			}	
			PA_ResetBgSys();
			PA_ResetSpriteSys();
			P1Stage();
			return 0;
		}
		if(PA_SpriteTouched(1)){
			for (i = 0; i >= -31; i--) {
				PA_SetBrightness(0, i);
				PA_SetBrightness(1, i);
				PA_WaitForVBL();
			}
			PA_ResetBgSys();
			PA_ResetSpriteSys();
			return 0;
		}
		if(PA_SpriteTouched(2)){
			PA_SetSpriteAnim(0,2,1);
			for (i = 0; i >= -31; i--) {
				PA_SetBrightness(0, i);
				PA_SetBrightness(1, i);
				PA_WaitForVBL(); 
			}	
			PA_ResetBgSys();
			PA_ResetSpriteSys();
			HowToPlay();
			return 0;
		}
		y ++;
		PA_WaitForVBL();
	}
	return 0;
}