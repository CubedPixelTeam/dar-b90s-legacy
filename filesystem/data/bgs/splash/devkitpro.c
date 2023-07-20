#include <PA_BgStruct.h>

extern const char devkitpro_Tiles[];
extern const char devkitpro_Map[];
extern const char devkitpro_Pal[];

const PA_BgStruct devkitpro = {
	PA_BgNormal,
	256, 192,

	devkitpro_Tiles,
	devkitpro_Map,
	{devkitpro_Pal},

	26240,
	{1536}
};
