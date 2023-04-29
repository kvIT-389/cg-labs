#ifndef WINDOW_H_INCLUDED_
#define WINDOW_H_INCLUDED_


#include "types.h"
#include "point.h"
#include "size.h"


/**
 * Structure which stores data such as current size associated
 * with one of the application windows specified by its @a id.
 * 
 * if @a id is equals to zero window is not
 * associated with any application window.
 */
typedef struct window
{
    _window_id_t id;

    Size size;
} Window;


/**
 * Creates a new window and initializes @a window instance
 * with data associated with created window.
 */
void initWindow(
    Window *window, const char *title,
    Size size, Point position
);

/**
 * Destroys the window specified by @a window
 * and associated with it OpenGL context.
 */
void destroyWindow(Window *window);


#endif  /* WINDOW_H_INCLUDED_ */
