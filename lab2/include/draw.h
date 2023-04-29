#ifndef DRAW_H_INCLUDED_
#define DRAW_H_INCLUDED_


#include "types.h"
#include "color.h"
#include "rect.h"
#include "texture.h"
#include "font.h"
#include "button.h"
#include "menu.h"


/**
 * Current window main drawing function.
 * Called each time @a display function called.
 */
void draw(void);

/**
 * Draws rectangle specified by @a rect
 * using @a color if it's given or current color otherwise.
 */
void drawRect(const Rect *rect, const Color *color);

/**
 * Draws rectangle frame specified by @a rect
 * using @a color if it's given or current color otherwise
 * and the given @a line_width.
 */
void drawRectFrame(
    const Rect *rect,
    const Color *color,
    const _line_width_t line_width
);

void drawTextLine(
    const unsigned char *text,
    const Point pos,
    const Font *font
);

void drawCharacter(
    const unsigned char character,
    const Point pos,
    const Font *font
);

/**
 * Draws texture in the rectangle specified by @a rect
 * using data from @a texture.
 * 
 * Rectangle @a texture_rect specifies area of the texture
 * which is used to draw and depends on texture size.
 * 
 * To use all texture data @a texture_rect pointer
 * should be equal to @c NULL.
 * 
 * Color @a fill_color specifies color which will be used
 * during rectangle drawing. Giving white color means to
 * draw texture "as is" with its source colors.
 */
void drawTexturedRect(
    const Rect *rect,
    const Texture *texture,
    const Rect *texture_rect,
    const Color *fill_color
);

/**
 * Draws button specified by @a button.
 */
void drawButton(const Button *button);

/**
 * Draws menu specified by @a menu.
 */
void drawMenu(const Menu *menu);


#endif  /* DRAW_H_INCLUDED_ */
