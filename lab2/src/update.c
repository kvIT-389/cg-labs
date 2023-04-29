#include <GL/glut.h>

#include "update.h"
#include "types.h"


const _time_t update_delay = 10;


void update(int value)
{
    if (glutGetWindow() > 0) glutPostRedisplay();

    glutTimerFunc(update_delay, update, value);
}

void runUpdateLoop(void)
{
    glutTimerFunc(update_delay, update, 0);
}
