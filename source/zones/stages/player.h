#ifndef PLAYER_H
#define PLAYER_H_INCLUDED
#include <PA9.h>
#include "common.h"

class APlayer{
	public:
		float X;
		float VX;

		int startingPosX;
		int startingPosY;
		int Y;
		int lives;

		float G;
		float SX;
		float SY;
		int timer;
		bool ground;
		int id;
		bool flip;
		int cbg;
		void create();
		void move();
		void gravity();
		void Update();
		int check_dpad_collision();
		int check_dpad_collision_left();
};

#endif