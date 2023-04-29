#ifndef COLLISION_H_INCLUDED_
#define COLLISION_H_INCLUDED_


#include <stdint.h>

#include "point.h"
#include "rect.h"


/**
 * Returns 1 if the point is inside the rectangle,
 * otherwise returns 0.
 * 
 * \param[in] point given point.
 * 
 * \param[in] rect given rectangle.
 */
uint8_t pointInRect(const Point point, const Rect *rect);


#endif  /* COLLISION_H_INCLUDED_ */
