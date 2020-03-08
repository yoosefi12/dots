#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "game_logic.h"

struct player players[2];
struct ground grnd = {.left = -0.75f, .right = +0.75f, .top = 0.75f, .bottom = -0.75f};

void setup()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void draw_player(struct player p)
{
    if (p.index == 0)
        glColor3f(1.0f, 0.0f, 0.0f);
    if (p.index == 1)
        glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(-0.01f + p.x, 0.01f + p.y, 0.01f + p.x, -0.01f + p.y);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // struct movement m1 = {.index = 0, .dx = 0.01f, .dy = -0.01f};
    // dots_apply_movement(players, m1, grnd);
    players[0].x += +0.02f;
    players[0].y += -0.2f;

    for (int i = 0; i < 2; ++i)
    {
        draw_player(players[i]);
    }

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    dots_init(players, grnd);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Client");

    setup();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}