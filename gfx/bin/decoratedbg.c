#include <PA_BgStruct.h>

extern const char decoratedbg_Tiles[];
extern const char decoratedbg_Map[];
extern const char decoratedbg_Pal[];

const PA_BgStruct decoratedbg = {
	PA_BgLarge,
	1024, 256,

	decoratedbg_Tiles,
	decoratedbg_Map,
	{decoratedbg_Pal},

	13248,
	{8192}
};
