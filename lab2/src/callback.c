#include <GL/gl.h>
#include <GL/glut.h>

#include "callback.h"
#include "draw.h"
#include "mainwindow.h"
#include "mainmenu.h"


void initCallbacks(void)
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(passiveMotion);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    draw();

    if (glutGet(GLUT_WINDOW_DOUBLEBUFFER)) {
        glutSwapBuffers();
    }
    else {
        glFlush();
    }
}

void reshape(_size_t width, _size_t height)
{
    main_window.size = (Size){width, height};

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void mouse(
    _mouse_button_t button,
    _mouse_button_state_t state,
    _coord_t x, _coord_t y
)
{
    Point position = {x, y};

    switch (button) {
        case GLUT_LEFT_BUTTON:
            switch (state) {
                case GLUT_DOWN:
                    menuMouseLeftDown(&main_menu, position);

                    break;

                case GLUT_UP:
                    menuMouseLeftUp(&main_menu, position);

                    break;
            }

            break;
    }
}

void motion(_coord_t x, _coord_t y)
{
    /* Code of mouse motion callback */
}

void passiveMotion(_coord_t x, _coord_t y)
{
    Point position = {x, y};

    menuMouseMove(&main_menu, position);
}


void keyboard(_key_t key, _coord_t x, _coord_t y)
{
    switch (key) {
        case 'q':
            destroyWindow(&main_window);
            break;
    }
}

void specialKeyboard(
    _special_key_t key,
    _coord_t x, _coord_t y
)
{
    /* Code of special keyboard callback */
}
