#include <PA_BgStruct.h>

extern const char Black_Tiles[];
extern const char Black_Map[];
extern const char Black_Pal[];

const PA_BgStruct Black = {
	PA_BgNormal,
	256, 192,

	Black_Tiles,
	Black_Map,
	{Black_Pal},

	5824,
	{1536}
};
