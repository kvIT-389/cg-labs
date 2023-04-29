#ifndef POINT_H_INCLUDED_
#define POINT_H_INCLUDED_


#include "types.h"


/**
 * Structure which stores point as two its coordinates i.e. x and y.
 * z-coordinate supposed to be 0.
 * 
 * Each coordinate is stored in terms of window pixels.
 */
typedef struct point
{
    _coord_t x;
    _coord_t y;
} Point;


#endif  /* POINT_H_INCLUDED_ */
