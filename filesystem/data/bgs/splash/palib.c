#include <PA_BgStruct.h>

extern const char palib_Tiles[];
extern const char palib_Map[];
extern const char palib_Pal[];

const PA_BgStruct palib = {
	PA_BgNormal,
	256, 192,

	palib_Tiles,
	palib_Map,
	{palib_Pal},

	18176,
	{1536}
};
