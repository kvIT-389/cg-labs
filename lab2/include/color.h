#ifndef COLOR_H_INCLUDED_
#define COLOR_H_INCLUDED_


#include "types.h"


/**
 * Structure which stores color as array of 4 its components
 * i.e. red, green, blue and alpha channels.
 */
typedef struct color
{
    _rgba_channel_t channels[4];
} Color;


/* Predefined colors */

/* Color #ffffff */
extern const Color white;

/* Color #dcdcdc */
extern const Color gainsboro;

/* Color #d3d3d3 */
extern const Color lightgray;

/* Color #c0c0c0 */
extern const Color silver;

/* Color #a9a9a9 */
extern const Color darkgray;

/* Color #808080 */
extern const Color gray;

/* Color #708090 */
extern const Color slategray;

/* Color #696969 */
extern const Color dimgray;


/**
 * Sets current OpenGL color.
 * 
 * \param color color to set.
 */
void setColor(const Color *color);


#endif  /* COLOR_H_INCLUDED_ */
