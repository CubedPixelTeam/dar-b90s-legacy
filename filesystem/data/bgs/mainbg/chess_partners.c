#include <PA_BgStruct.h>

extern const char chess_partners_Tiles[];
extern const char chess_partners_Map[];
extern const char chess_partners_Pal[];

const PA_BgStruct chess_partners = {
	PA_BgNormal,
	256, 256,

	chess_partners_Tiles,
	chess_partners_Map,
	{chess_partners_Pal},

	832,
	{2048}
};
