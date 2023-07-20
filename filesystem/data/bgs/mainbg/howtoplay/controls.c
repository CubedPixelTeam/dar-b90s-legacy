#include <PA_BgStruct.h>

extern const char controls_Tiles[];
extern const char controls_Map[];
extern const char controls_Pal[];

const PA_BgStruct controls = {
	PA_BgNormal,
	256, 192,

	controls_Tiles,
	controls_Map,
	{controls_Pal},

	10944,
	{1536}
};
