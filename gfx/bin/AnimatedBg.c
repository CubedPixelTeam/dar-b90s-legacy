#include <PA_BgStruct.h>

extern const char AnimatedBg_Tiles[];
extern const char AnimatedBg_Map[];
extern const char AnimatedBg_Pal[];

const PA_BgStruct AnimatedBg = {
	PA_BgNormal,
	256, 256,

	AnimatedBg_Tiles,
	AnimatedBg_Map,
	{AnimatedBg_Pal},

	2752,
	{2048}
};
