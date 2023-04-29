#ifndef BUTTON_H_INCLUDED_
#define BUTTON_H_INCLUDED_


#include "point.h"
#include "rect.h"
#include "color.h"


typedef void (*action_fn)(void);


typedef enum
{
    ButtonReleased,
    ButtonHovered,
    ButtonPressed
} ButtonState;


/**
 * Structure which stores data associated with some button
 * such as its text, rectangle and button state which are
 * one of \ref ButtonState enum.
 */
typedef struct button
{
    char *text;

    Rect rect;

    ButtonState state;
    Color palette[3];

    action_fn on_click;
} Button;


/**
 * Function which is called after mouse left button pressed
 * at the given position and handles it for the given button.
 * 
 * \param button given button.
 * \param[in] pos point in which mouse moved.
 */
void buttonMouseLeftDown(Button *button, const Point pos);

/**
 * Function which is called after mouse left button release
 * at the given position and handles it for the given button.
 * 
 * \param button given button.
 * \param[in] pos point in which mouse moved.
 */
void buttonMouseLeftUp(Button *button, const Point pos);

/**
 * Function which is called after mouse move
 * to the given position and handles it for the given button.
 * 
 * \param button given button.
 * \param[in] pos point in which mouse moved.
 */
void buttonMouseMove(Button *button, const Point pos);


#endif  /* BUTTON_H_INCLUDED_ */
