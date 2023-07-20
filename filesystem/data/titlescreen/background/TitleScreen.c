#include <PA_BgStruct.h>

extern const char TitleScreen_Tiles[];
extern const char TitleScreen_Map[];
extern const char TitleScreen_Pal[];

const PA_BgStruct TitleScreen = {
	PA_BgNormal,
	256, 192,

	TitleScreen_Tiles,
	TitleScreen_Map,
	{TitleScreen_Pal},

	13056,
	{1536}
};
