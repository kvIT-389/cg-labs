#ifndef FONT_H_INCLUDED_
#define FONT_H_INCLUDED_


#include "types.h"
#include "color.h"
#include "charset.h"


/**
 * Structure which stores data related to some font
 * such as charset which used to draw characters,
 * color which used to fill characters,
 * space between characters and height of drew text line.
 */
typedef struct font
{
    const Charset *charset;

    const Color *color;

    _size_t letter_spacing;
    _size_t line_height;
} Font;


#endif  /* FONT_H_INCLUDED_ */
