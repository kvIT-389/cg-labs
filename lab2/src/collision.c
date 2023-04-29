#include <stdint.h>

#include "collision.h"
#include "point.h"
#include "rect.h"


uint8_t pointInRect(Point point, const Rect *rect)
{
    return (rectLeft(rect) <= point.x) &&
           (point.x <= rectRight(rect)) &&
           (rectTop(rect) <= point.y) &&
           (point.y <= rectBottom(rect));
}
