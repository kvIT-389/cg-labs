#include <GL/glut.h>

#include "mainwindow.h"
#include "mainmenu.h"
#include "callback.h"
#include "update.h"
#include "charset.h"
#include "point.h"
#include "size.h"


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);

    initWindow(
        &main_window, "OpenGL 2D",
        (Size){480, 480},
        (Point){200, 200}
    );

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    charsetLoad(&default_charset, "charsets/comic_sans_ms_1024.png");

    initMainMenu();

    initCallbacks();
    runUpdateLoop();

    glutMainLoop();

    charsetFree(&default_charset);

    return 0;
}
