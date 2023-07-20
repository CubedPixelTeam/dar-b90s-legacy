#include "player.h"
#include "all_gfx.h"

int distance = 0;
int upDistance = 0;

void APlayer::create(){
	PA_LoadSpritePal(1,this->id,(void*)DS_Pal);
	PA_CreateSprite(1,this->id,(void*)DS_Sprite,OBJ_SIZE_16X32,1,0,this->X,this->Y);
	PA_SetSpriteRotEnable(1,this->id,this->id);
	PA_SetSpriteDblsize(1,this->id,1);
	PA_SetRotsetNoAngle(1,this->id,178,178);
}
int bg_x = 0;
void APlayer::move(){
	if(PA_EasyBgGetPixel(1,this->cbg,this->SX + 9, this->Y + 16) ==0 && Pad.Held.Left) {
		this->X -= 3;
	}
	else if(PA_EasyBgGetPixel(1,this->cbg,this->SX + 23,this->Y + 16)==0 && Pad.Held.Right) {
		this->X += 3;
	}
	else if(!((Pad.Held.Left)||(Pad.Held.Right))) {
		PA_SpriteAnimPause(1, 0, 1);
		this->VX = 0;
	}
	if(Pad.Newpress.B) this->flip = true;
	if(Pad.Newpress.Right) {
		PA_StartSpriteAnim(1, 0, 0, 3, 10);	
		this->flip = false;
		PA_SetRotsetNoAngle(1,this->id,178,178);
	}
	else if(Pad.Newpress.Left) {
		PA_StartSpriteAnim(1, 0, 7, 10, 10);	
		this->flip = true;
		PA_SetRotsetNoAngle(1,this->id,178,178);
	}
	//NFlib stolen code
	if(this->X < 0) this->X = 0;
	bg_x = (this->X - 58);
	if(bg_x < 0) bg_x = 0;
	this->SX = (this->X - bg_x) - 4;

	PA_EasyBgScrollXY(1,this->cbg,bg_x,false);
	PA_SetSpriteXY(1,0,this->SX,this->Y - 25);
}

//PLEASE IGNORE THIS PART THAT IS JUST TOO MESSY.

void APlayer::gravity(){
	int i = 0;
	 if(
	//collision left to right, no up.
	PA_EasyBgGetPixel(1,this->cbg,this->SX + 20,(this->Y + 32) + this->G)!= 0 ||
 	PA_EasyBgGetPixel(1,this->cbg,this->SX + 12,(this->Y + 32) + this->G)!= 0 ||
	//same but with up collisions
	PA_EasyBgGetPixel(1,this->cbg,this->SX + 20,this->Y + this->G)!= 0 ||
 	PA_EasyBgGetPixel(1,this->cbg,this->SX + 12,this->Y + this->G)!= 0){

    for (i = 0; i <= this->G; i++) {
      if(PA_EasyBgGetPixel(1,this->cbg,this->SX + 20,(this->Y + 32) + distance)==0 ||
	  PA_EasyBgGetPixel(1,this->cbg,this->SX + 12,(this->Y + 32) + distance)==0 ||

	  PA_EasyBgGetPixel(1,this->cbg,this->SX + 20,this->Y + distance)==0 ||
	  PA_EasyBgGetPixel(1,this->cbg,this->SX + 12,this->Y + distance)==0) {
        distance = distance + 1;
      }
    }
    this->Y = this->Y + distance;
    distance = 0;
    this->G = 0;
  }
  else {
    this->G = this->G + 0.5;
    this->Y = this->Y + this->G;
  }
  if(PA_EasyBgGetPixel(1,this->cbg,this->SX + 20,this->Y + 32)!= 0 ||
  PA_EasyBgGetPixel(1,this->cbg,this->SX + 12,this->Y + 32)!= 0){
    for (i = 0; i <= 16; i++) {
      if(PA_EasyBgGetPixel(1,this->cbg,this->SX + 20,(this->Y + 32) + upDistance)!=0||
  		PA_EasyBgGetPixel(1,this->cbg,this->SX + 12,(this->Y + 32) + upDistance)!=0){
        upDistance = upDistance - 1;
      }
    }
    this->Y = this->Y + (upDistance + 2);
    upDistance = 0;
    this->G = 0;
	if(Pad.Newpress.A) {
		this->ground = true;
		this->timer = 0;
	}
  }
if(Pad.Held.A && this->ground == true) {
  	this->timer ++;
	if(this->timer > 8) {
		this->ground = false; 
		this->timer = 0;
	}
	this->G = -5;
  }
if(Pad.Released.A) {
	this->timer = 0;
	this->ground = false;
}
}