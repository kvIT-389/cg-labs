#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "point.h"
#include "size.h"
#include "rect.h"
#include "button.h"
#include "mainwindow.h"


Menu main_menu;


void initMainMenu(void)
{
    menuAddButton(
        &main_menu, "Start",
        (Point){10, 10}, (Size){128, 32},
        0
    );
    menuAddButton(
        &main_menu, "Settings",
        (Point){10, 60}, (Size){128, 32},
        0
    );
    menuAddButton(
        &main_menu, "Quit",
        (Point){10, 110}, (Size){128, 32},
        &quitCallback
    );
}

void menuAddButton(
    Menu *menu,
    const char *text,
    const Point position,
    const Size size,
    const action_fn on_click_callback
)
{
    ++menu->buttons_count;
    menu->buttons = realloc(
        menu->buttons,
        menu->buttons_count * sizeof(Button)
    );

    Button *button = menu->buttons + (menu->buttons_count - 1);

    button->text = calloc(strlen(text), sizeof(*button->text));
    strcpy(button->text, text);

    button->rect = getRect(position, size);

    button->state = ButtonReleased;

    button->palette[ButtonReleased] = gainsboro;
    button->palette[ButtonHovered] = lightgray;
    button->palette[ButtonPressed] = darkgray;

    button->on_click = on_click_callback;
}

void menuClear(Menu *menu)
{
    while (menu->buttons_count > 0) {
        free(menu->buttons[--menu->buttons_count].text);
    }

    free(menu->buttons);
}


void menuMouseLeftDown(Menu *menu, Point position)
{
    for (int i = 0; i < menu->buttons_count; ++i) {
        buttonMouseLeftDown(menu->buttons + i, position);
    }
}

void menuMouseLeftUp(Menu *menu, Point position)
{
    for (int i = 0; i < menu->buttons_count; ++i) {
        buttonMouseLeftUp(menu->buttons + i, position);
    }
}

void menuMouseMove(Menu *menu, Point position)
{
    for (int i = 0; i < menu->buttons_count; ++i) {
        buttonMouseMove(menu->buttons + i, position);
    }
}


void quitCallback(void)
{
    destroyWindow(&main_window);
}
