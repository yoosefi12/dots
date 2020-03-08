#include <stdio.h>
#include "game_logic.h"

int main()
{
    struct player players[2];
    struct ground grnd = {.left = 0, .right = 10, .top = 0, .bottom = 10};
    init(players, grnd);
    struct movement m1 = {.index = 0, .dx = 100, .dy = 100};
    apply_movement(players, m1, grnd);
    printf("%i %i %i", players[0].index, players[0].x, players[0].y);
    return 0;
}
