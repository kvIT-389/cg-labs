#ifndef RECT_H_INCLUDED_
#define RECT_H_INCLUDED_


#include "types.h"
#include "point.h"
#include "size.h"


/**
 * Structure which stores rectangle as array of its vertices.
 */
typedef struct rect
{
    Point vertices[4];
} Rect;


/**
 * Gets a new rectangle from its position and size.
 * 
 * \param[in] pos rectangle position i.e.
 *                point with minimal coordinates.
 * \param[in] size rectangle size.
 * 
 * \return New rectangle i.e. \a Rect instance.
 */
Rect getRect(const Point pos, const Size size);


/**
 * Returns left edge coordinate of the rectangle.
 * 
 * \param[in] rect given rectangle.
 */
_coord_t rectLeft(const Rect *rect);

/**
 * Returns right edge coordinate of the rectangle.
 * 
 * \param[in] rect given rectangle.
 */
_coord_t rectRight(const Rect *rect);

/**
 * Returns top edge coordinate of the rectangle.
 * 
 * \param[in] rect given rectangle.
 */
_coord_t rectTop(const Rect *rect);

/**
 * Returns bottom edge coordinate of the rectangle.
 * 
 * \param[in] rect given rectangle.
 */
_coord_t rectBottom(const Rect *rect);


/**
 * Returns width of the rectangle.
 * 
 * \param[in] rect given rectangle.
 */
_size_t rectWidth(const Rect *rect);

/**
 * Returns height of the rectangle.
 * 
 * \param[in] rect given rectangle.
 */
_size_t rectHeight(const Rect *rect);


/**
 * Returns position of the rectangle.
 * 
 * \param[in] rect given rectangle.
 * 
 * \return Position of the rectangle
 *         i.e. point with minimal coordinates.
 */
Point rectPos(const Rect *rect);

/**
 * Returns size of the rectangle.
 * 
 * \param[in] rect given rectangle.
 */
Size rectSize(const Rect *rect);


#endif  /* RECT_H_INCLUDED_ */
