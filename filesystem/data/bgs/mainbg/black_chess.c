#include <PA_BgStruct.h>

extern const char black_chess_Tiles[];
extern const char black_chess_Map[];
extern const char black_chess_Pal[];

const PA_BgStruct black_chess = {
	PA_BgNormal,
	256, 256,

	black_chess_Tiles,
	black_chess_Map,
	{black_chess_Pal},

	832,
	{2048}
};
