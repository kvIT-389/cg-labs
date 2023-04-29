#ifndef MENU_H_INCLUDED_
#define MENU_H_INCLUDED_


#include <stdint.h>

#include "button.h"
#include "point.h"
#include "size.h"


/**
 * Structure which stores set of buttons related to each other.
 */
typedef struct menu {
    /**
     * Total count of menu buttons.
     */
    uint8_t buttons_count;

    /**
     * Array of menu buttons.
     */
    Button *buttons;
} Menu;


/**
 * Fills main menu specified by \a main_menu with buttons.
 */
void initMainMenu(void);


/**
 * Creates new button from the given text, position, size
 * and with the given callback function
 * and adds it to the given menu.
 * 
 * \param menu menu to which button added.
 * 
 * \param[in] text text of added button.
 * \param[in] pos position of added button.
 * \param[in] size size of added button.
 * \param[in] on_click_callback callback function of added button
 *                              which called when button clicked.
 */
void menuAddButton(
    Menu *menu,
    const char *text,
    const Point pos,
    const Size size,
    const action_fn on_click_callback
);

/**
 * Clears menu from all its buttons.
 * 
 * \param menu menu which need to be cleared.
 */
void menuClear(Menu *menu);


/**
 * Function which is called after mouse left button pressed
 * at the given position and handles it for the given menu.
 * 
 * \param menu given menu.
 * \param[in] pos point in which mouse moved.
 */
void menuMouseLeftDown(Menu *menu, Point position);

/**
 * Function which is called after mouse left button release
 * at the given position and handles it for the given menu.
 * 
 * \param menu given menu.
 * \param[in] pos point in which mouse moved.
 */
void menuMouseLeftUp(Menu *menu, Point position);

/**
 * Function which is called after mouse move
 * to the given position and handles it for the given menu.
 * 
 * \param menu given menu.
 * \param[in] pos point in which mouse moved.
 */
void menuMouseMove(Menu *menu, const Point pos);


/**
 * Click callback for "Quit" button of main menu.
 */
void quitCallback(void);


#endif  /* MENU_H_INCLUDED_ */
