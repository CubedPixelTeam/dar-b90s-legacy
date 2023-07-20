#include <PA_BgStruct.h>

extern const char level_entry_Tiles[];
extern const char level_entry_Map[];
extern const char level_entry_Pal[];

const PA_BgStruct level_entry = {
	PA_BgNormal,
	256, 192,

	level_entry_Tiles,
	level_entry_Map,
	{level_entry_Pal},

	48256,
	{1536}
};
