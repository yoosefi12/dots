#include<stdio.h>
#include "game_logic.h"

void dots_init(struct player players[], struct ground grnd)
{
    players[0].index = 0;
    players[0].x = grnd.left;
    players[0].y = grnd.top;

    players[1].index = 1;
    players[1].x = grnd.right;
    players[1].y = grnd.bottom;
}

int dots_detect_collision(struct player players[], struct movement mvnt, struct ground grnd)
{
    int player_new_x = players[mvnt.index].x + mvnt.dx;
    int player_new_y = players[mvnt.index].y + mvnt.dy;
    int ground_collided = player_new_x < grnd.left ||
                          player_new_x > grnd.right ||
                          player_new_y > grnd.top ||
                          player_new_y < grnd.bottom;
    return ground_collided;
}

void dots_apply_movement(struct player players[], struct movement mvnt, struct ground grnd)
{
    // if (!dots_detect_collision(players, mvnt, grnd))
    {
        players[mvnt.index].x += mvnt.dx;
        players[mvnt.index].y += mvnt.dy;
        // printf("%s", "Moved");
    }
    // else
    // {
    //     printf("%s", "Not moved");
    // }
}