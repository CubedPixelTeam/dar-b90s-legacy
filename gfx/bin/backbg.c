#include <PA_BgStruct.h>

extern const char backbg_Tiles[];
extern const char backbg_Map[];
extern const char backbg_Pal[];

const PA_BgStruct backbg = {
	PA_BgLarge,
	1024, 256,

	backbg_Tiles,
	backbg_Map,
	{backbg_Pal},

	18240,
	{8192}
};
