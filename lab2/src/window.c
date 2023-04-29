#include <string.h>

#include <GL/glut.h>

#include "window.h"
#include "types.h"
#include "mainwindow.h"


Window main_window;


void initWindow(
    Window *window, const char *title,
    Size size, Point position
)
{
    if (window->id) return;  /* Error: window is already initialized. */

    glutInitWindowSize(size.width, size.height);
    glutInitWindowPosition(position.x, position.y);

    window->id = glutCreateWindow(title);
    window->size = size;
}

void destroyWindow(Window *window)
{
    glutDestroyWindow(window->id);
    window->id = 0;
}
