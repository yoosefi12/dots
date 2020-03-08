struct player
{
    char index;
    float x, y;
};

struct movement
{
    char index;
    float dx, dy;
};

struct ground
{
    float left, top, right, bottom;
};

void dots_init(struct player players[], struct ground grnd);
int dots_detect_collision(struct player players[], struct movement mvnt, struct ground grnd);
void dots_apply_movement(struct player players[], struct movement mvnt, struct ground grnd);


