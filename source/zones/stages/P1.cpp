#include "player.h"
#include "P1.h"
#include "all_gfx.h"
#include <PA9.h>
#include "objects.h"
#include "common.h"
#include "P2.h"


int P1Stage(){
	APlayer Player;
	int timer = 0;
	int i = 0;
	ASpring Spring;
	Player.id = 0;
	Player.cbg = 1;
	Player.Y = 145;
	Player.startingPosX = 0;
	Player.startingPosY = 145;

	PA_ResetBgSys();
	PA_InitText(1, 1);
	PA_InitBgTrans(1);

	FAT_LoadBackground(1, 3, "nitro:/data/bgs/level_entry");
	PA_OutputSimpleText(1, 7, 12, "Fever Dream Act 1");

	PA_SetBrightness(0, 0);
	PA_SetBrightness(1, 0);
	for (i = TRANS_LENGTH; i >= 0; i--)
	{
		PA_BgTransLeftRight(1, 0, 1, i);
		PA_WaitForVBL();
	}
	PA_WaitFor(Pad.Newpress.Anykey);
	for (i = 0; i <= TRANS_LENGTH; i++)
	{
		PA_BgTransLeftRight(1, 0, 1, i);
		PA_WaitForVBL();
	}
	PA_SetBrightness(1, -31);
	PA_ResetBgSys();
	PA_EnableSpecialFx(1, SFX_ALPHA, SFX_BG3 | SFX_BD, SFX_BG3 | SFX_BD);

	PA_LoadBackground(1, 3, &AnimatedBg);
	PA_LoadBackground(1,2,&backbg);
	PA_LoadBackground(1, 1, &decoratedbg);
	PA_InitText(0, 0);
	PA_SetSFXAlpha(1, 15, 15);

	for (i = -31; i <= 0; i++)
	{
		PA_SetBrightness(0, i);
		PA_SetBrightness(1, i);
		PA_WaitForVBL();
		PA_WaitForVBL();
	}
	Player.create();
	Player.lives = 5;
	bool bg_animation = false;
	PA_VBLFunctionInit(AS_SoundVBL);
	while (1)
	{
		AS_MP3StreamPlay("nitro:/data/music/P1.mp3");
		timer++;
		if (timer > 60)
		{
			if (bg_animation == false)
			{
				PA_SetSFXAlpha(1, 8, 8);
				bg_animation = true;
			}
			else if (bg_animation == true)
			{
				PA_SetSFXAlpha(1, 15, 15);
				bg_animation = false;
			}
			timer = 0;
		}
		if(Spring.collision(Player.X,Player.Y,263,145)) Player.G = -10;
		else if(Spring.collision(Player.X,Player.Y,279,145)) Player.G = -10;
		else if(Spring.collision(Player.X,Player.Y,295,145)) Player.G = -10;
		else if(Spring.collision(Player.X,Player.Y,481,71)) Player.G = -7;
		else if(Spring.collision(Player.X,Player.Y,526,71)) Player.G = -7;
		else if(Spring.collision(Player.X,Player.Y,481,71)) Player.G = -7;

		Player.move();
		Player.gravity();
		Player.Update();
		if(Player.X > 633 && Player.Y > 150){
			PA_SetSpritePrio(1,0,1);
			PA_InitBgTrans(1);
			for (i = 0; i <= TRANS_LENGTH; i++){
				PA_BgTransLeftRight(1, 0, 1, i);
				PA_WaitForVBL();
			}
			AS_MP3Stop();
			PA_Init();
			P2Stage();
			return 0;
		}
		PA_EasyBgScrollXY(1,1,bgscroll_x,false);
		PA_EasyBgScrollXY(1,2,bgscroll_x,false);
		PA_OutputText(0,0,0,"Darnell: %d", Player.lives);
		PA_WaitForVBL();
	}
	return 0;
}