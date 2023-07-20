#include "player.h"
#include "P1.h"
#include "all_gfx.h"
#include <PA9.h>
#include "objects.h"
#include "common.h"
#include "P2.h"


int P2Stage(){
	APlayer Player;
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
	PA_OutputSimpleText(1, 7, 12, "Fever Dream Act 2");

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

	PA_LoadBackground(1,2,&fvdrza2bg);
	PA_LoadBackground(1,1,&fvdrza2cb);
	PA_InitText(0, 0);

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

		if(Spring.collision(Player.X,Player.Y,121,158)) Player.G = -10;

		Player.move();
		Player.gravity();
		Player.Update();
		PA_EasyBgScrollXY(1,1,bgscroll_x,false);
		PA_EasyBgScrollXY(1,2,bgscroll_x,false);
		PA_ClearTextBg(0);
		PA_OutputText(0,0,0,"Darnell: %d", Player.lives);
		PA_OutputText(0,0,1,"    %f0     %f0    ",Player.X, Player.Y);
		PA_WaitForVBL();
	}
	return 0;
}