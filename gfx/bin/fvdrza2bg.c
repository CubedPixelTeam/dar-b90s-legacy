#include <PA_BgStruct.h>

extern const char fvdrza2bg_Tiles[];
extern const char fvdrza2bg_Map[];
extern const char fvdrza2bg_Pal[];

const PA_BgStruct fvdrza2bg = {
	PA_BgNormal,
	256, 192,

	fvdrza2bg_Tiles,
	fvdrza2bg_Map,
	{fvdrza2bg_Pal},

	8960,
	{1536}
};
