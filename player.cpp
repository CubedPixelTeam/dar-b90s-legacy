#include "player.h"
#include "objects.h"
#include "all_gfx.h"

int distance = 0;
int upDistance = 0;

int bgscroll_x;
void APlayer::create(){
	PA_LoadSpritePal(1,this->id,(void*)DS_Pal);
	PA_CreateSprite(1,this->id,(void*)DS_Sprite,OBJ_SIZE_16X32,1,0,this->X,this->Y);
	PA_SetSpriteRotEnable(1,this->id,this->id);
	PA_SetSpriteDblsize(1,this->id,1);
	PA_SetRotsetNoAngle(1,this->id,178,178);
}
int bottomdistance = 0;
int APlayer::check_dpad_collision(){
	for(int i = 0; i <31;i++){
		if(PA_EasyBgGetPixel(1,this->cbg,this->SX + 23, this->Y + i) != 0) return 1;
	}
	return 0;
}
int APlayer::check_dpad_collision_left(){
	for(int i = 0; i <31;i++){
		if(PA_EasyBgGetPixel(1,this->cbg,this->SX + 9, this->Y + i) != 0) return 1;
	}
	return 0;
}
int speed_cap = 3;
void APlayer::move(){
	if(this->check_dpad_collision_left() == 0&& Pad.Held.Left) {
		if(this->VX < speed_cap) this->VX += 0.1;
		this->X -= this->VX;
		PA_SpriteAnimPause(1, 0, 0);
	}
	else if(this->check_dpad_collision() == 0&& Pad.Held.Right) {
		if(this->VX < speed_cap) this->VX += 0.1;
		this->X += this->VX;
		PA_SpriteAnimPause(1, 0, 0);
	}
	else if(!(Pad.Held.Left)||(Pad.Held.Right)){
		this->VX = 0;
		PA_SpriteAnimPause(1,0,1);
		if(this->flip == true) PA_SetSpriteAnimFrame(1,0,8);
		else PA_SetSpriteAnimFrame(1,0,0);
	}
	if(Pad.Newpress.Right) {
		PA_StartSpriteAnim(1, 0, 1, 4, 10);	
		this->flip = false;
	}
	else if(Pad.Newpress.Left) {
		PA_StartSpriteAnim(1, 0, 9, 12, 10);	
		this->flip = true;
	}
	//NFlib stolen code
	if(this->X < 0) this->X = 0;
	bgscroll_x = (this->X - 40);
	if(bgscroll_x < 0) bgscroll_x = 0;
	this->SX = (this->X - bgscroll_x) - 4;
	PA_EasyBgScrollXY(1,2,bgscroll_x,false);
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
    this->ground = false;
  }
  else {
    this->G = this->G + 0.4;
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
	if(Pad.Newpress.A || Pad.Newpress.B) {
		this->ground = true;
		this->timer = 0;
	}
  }
if((Pad.Held.A || Pad.Held.B) && this->ground == true) {
  	this->timer ++;
	if(this->timer > 16) {
		this->ground = false; 
		this->timer = 0;
		this->G ++;
	}
	this->G = -3;
  }
if(Pad.Released.A || Pad.Released.B) {
	this->timer = 0;
	this->ground = false;
}
if(this->Y > 192){
	if(this->lives > 1) {
		this->X = this->startingPosX;
		this->Y = this->startingPosY;
		lives --;
	}
	else{
		PA_PowerOff();
	}
}
}