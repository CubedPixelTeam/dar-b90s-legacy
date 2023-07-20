#include <PA9.h>
#include "objects.h"
#include "player.h"
#include "all_gfx.h"
extern APlayer Player;
int ASpring::collision(int PlayerX, int PlayerY, int springX, int springY){
    if((PlayerX < springX + 16 && PlayerX > springX - 16) &&
    (PlayerY < springY + 16 && PlayerY > springY - 16)) {
        return 1; //yes
    }
    else return 0; //no
}