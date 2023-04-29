#ifndef SIZE_H_INCLUDED_
#define SIZE_H_INCLUDED_


#include "types.h"


/**
 * Structure which stores rectangle size
 * as values of its width and height.
 * 
 * Each size component is stored in terms of window pixels.
 */
typedef struct size
{
    _size_t width;
    _size_t height;
} Size;


#endif  /* SIZE_H_INCLUDED_ */
