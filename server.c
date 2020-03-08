#include <stdio.h>
#include "game_logic.h"

int main()
{
    struct player players[2];
    struct ground grnd = {.left = -0.75f, .right = +0.75f, .top = 0.75f, .bottom = -0.75f};
    dots_init(players, grnd);

    printf("%i %i %i", players[0].index, players[0].x, players[0].y);
    return 0;
}
