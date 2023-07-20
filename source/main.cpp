#include <PA9.h>
#include "all_gfx.h"
#include "zones/HowToPlay.h"
#include "zones/MainMenu.h"
#include "debug.h"

void ErrorHandeling(void){
	PA_InitText(1,0);	
	if(!nitroFSInit()){
		PA_SetTextCol(1,31,0,0);
		PA_OutputSimpleText(1,0,0,"ERROR: NF01\n\nWithout nitroFS the game can't load its assets.\nCannot continue.\nPlease visit cubedpixelteam.gitub.com for more information.");		
		while(1) PA_WaitForVBL();
	}
	PA_VBLFunctionInit(AS_SoundVBL);
	PA_OutputSimpleText(1,0,0,"aslib init, if freezes then report.");
	AS_Init(AS_MODE_MP3 | AS_NO_DELAY | AS_MODE_16CH);
	PA_ClearTextBg(1);
	AS_SetDefaultSettings(AS_PCM_8BIT, 11025, AS_NO_DELAY);
	/* libFAT disabled.
	if(!fatInitDefault()){
		PA_SetTextCol(1, 28,23,0);
		PA_OutputSimpleText(1,0,0,"ERROR: FL01\n\nWithout libFAT we cannot save your progress.\nPress any key to continue.\nPlease visit cubedpixelteam.gitub.com for more information.");		
		PA_WaitFor(Pad.Newpress.A);		
		PA_ClearTextBg(1);
	}*/
}
int main(){
	int i = 0;
	PA_Init();
	ErrorHandeling();
	
	for(i = 0; i < 30;i++) {
		if(Pad.Newpress.B) {
			debugmenu();
			return 0;
		}
		PA_WaitForVBL();
	}

	//Splash screen.
	PA_ClearTextBg(1);
	PA_OutputSimpleText(1,2,10,"Cubed Pixel Team Presents");
	for (i = -31; i <= 0; i++) {
		PA_SetBrightness(0, i);
		PA_SetBrightness(1, i);
		PA_WaitForVBL(); 
	}
	for(i = 0; i < 60;i++) PA_WaitForVBL();
	for (i = 0; i >= -31; i--) {
		PA_SetBrightness(0, i);
		PA_SetBrightness(1, i);
		PA_WaitForVBL(); 
	}	
	PA_ClearTextBg(1);
	MainMenu();
	return 0;
}
