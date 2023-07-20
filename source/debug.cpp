#include <PA9.h>
#include "debug.h"
#include "zones/stages/P1.h"
#include "zones/stages/P2.h"

int debugmenu(){
	PA_Init();
	PA_InitText(0,0);
	PA_InitText(1,0);
	PA_OutputSimpleText(1,0,0,"Welcome to the secret debug menuprogrammer!");
	PA_OutputSimpleText(1,0,3,"Game data:\nB90s Engine: 0.2T\nGameVer:Id011");
	int text = 0;
	while(1){
		if(Pad.Newpress.Up) text --;
		else if(Pad.Newpress.Down) text ++;
		PA_ClearTextBg(0);
		PA_OutputSimpleText(0,0,text,">");
		PA_OutputSimpleText(0,1,0,"Fever Dream Zone act 1");
		PA_OutputSimpleText(0,1,1,"Fever Dream Zone act 2");
		if(Pad.Newpress.A){
			switch(text){
			case 0:
				P1Stage();
				return 0;
			break;
			case 1:
				P2Stage();
				return 0;
			break;
			}
		}
		PA_WaitForVBL();
	}
	return 0;
}