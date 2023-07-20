#include <PA_BgStruct.h>

extern const char betacubed_Tiles[];
extern const char betacubed_Map[];
extern const char betacubed_Pal[];

const PA_BgStruct betacubed = {
	PA_BgNormal,
	256, 192,

	betacubed_Tiles,
	betacubed_Map,
	{betacubed_Pal},

	48128,
	{1536}
};
