#include <PA_BgStruct.h>

extern const char help_Tiles[];
extern const char help_Map[];
extern const char help_Pal[];

const PA_BgStruct help = {
	PA_BgNormal,
	256, 512,

	help_Tiles,
	help_Map,
	{help_Pal},

	50944,
	{4096}
};
