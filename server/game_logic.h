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

void init(struct player players[], struct ground grnd);
int detect_collision(struct player players[], struct movement mvnt, struct ground grnd);
void apply_movement(struct player players[], struct movement mvnt, struct ground grnd);


