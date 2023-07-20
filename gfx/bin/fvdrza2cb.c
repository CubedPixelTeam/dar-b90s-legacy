#include <PA_BgStruct.h>

extern const char fvdrza2cb_Tiles[];
extern const char fvdrza2cb_Map[];
extern const char fvdrza2cb_Pal[];

const PA_BgStruct fvdrza2cb = {
	PA_BgLarge,
	768, 256,

	fvdrza2cb_Tiles,
	fvdrza2cb_Map,
	{fvdrza2cb_Pal},

	21952,
	{6144}
};
