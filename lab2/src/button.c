#include <stdio.h>

#include "button.h"
#include "point.h"
#include "collision.h"


void buttonMouseLeftDown(Button *button, const Point pos)
{
    if (pointInRect(pos, &button->rect)) {
        button->state = ButtonPressed;
    }
}

void buttonMouseLeftUp(Button *button, const Point pos)
{
    if (button->state != ButtonPressed) return;

    if (pointInRect(pos, &button->rect)) {
        printf("%s pressed.\n", button->text);

        if (button->on_click) {
            button->on_click();
        }
    }

    button->state = ButtonReleased;
}

void buttonMouseMove(Button *button, const Point pos)
{
    if (button->state == ButtonPressed) return;

    if (pointInRect(pos, &button->rect)) {
        button->state = ButtonHovered;
    }
    else {
        button->state = ButtonReleased;
    }
}
