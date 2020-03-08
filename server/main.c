#include <stdio.h>

struct player
{
    char index;
    int x, y;
};

struct movement
{
    char index;
    int dx, dy;
};

struct ground
{
    int left, top, right, bottom;
};

void init(struct player players[], struct ground grnd)
{
    printf("%p\n", players);
    players[0].index = 0;
    players[0].x = grnd.left;
    players[0].y = grnd.top;

    players[1].index = 1;
    players[1].x = grnd.right;
    players[1].y = grnd.bottom;
}

int detect_collision(struct player players[], struct movement mvnt, struct ground grnd)
{
    int player_new_x = players[mvnt.index].x + mvnt.dx;
    int player_new_y = players[mvnt.index].y + mvnt.dy;
    int ground_collided = player_new_x < grnd.left ||
                          player_new_x > grnd.right ||
                          player_new_y < grnd.top ||
                          player_new_y > grnd.bottom;
    return ground_collided;
}

void apply_movement(struct player players[], struct movement mvnt, struct ground grnd)
{
    if (!detect_collision(players, mvnt, grnd))
    {
        players[mvnt.index].x += mvnt.dx;
        players[mvnt.index].y += mvnt.dy;
    }
}



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
