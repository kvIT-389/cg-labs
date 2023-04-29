#include "rect.h"
#include "types.h"
#include "point.h"
#include "size.h"


Rect getRect(const Point position, const Size size)
{
    return (Rect){
        position.x, position.y,
        position.x, position.y + size.height,
        position.x + size.width, position.y + size.height,
        position.x + size.width, position.y
    };
}


_coord_t rectLeft(const Rect *rect)
{
    if (!rect) {
        return 0;
    }

    return rect->vertices[0].x;
}

_coord_t rectRight(const Rect *rect)
{
    if (!rect) {
        return 0;
    }

    return rect->vertices[2].x;
}

_coord_t rectTop(const Rect *rect)
{
    if (!rect) {
        return 0;
    }

    return rect->vertices[0].y;
}

_coord_t rectBottom(const Rect *rect)
{
    if (!rect) {
        return 0;
    }

    return rect->vertices[2].y;
}


_size_t rectWidth(const Rect *rect)
{
    if (!rect) {
        return 0;
    }

    return rectRight(rect) - rectLeft(rect);
}

_size_t rectHeight(const Rect *rect)
{
    if (!rect) {
        return 0;
    }

    return rectBottom(rect) - rectTop(rect);
}


Point rectPos(const Rect *rect)
{
    if (!rect) {
        return (Point){};
    }

    return rect->vertices[0];
}

Size rectSize(const Rect *rect)
{
    if (!rect) {
        return (Size){};
    }

    return (Size){rectWidth(rect), rectHeight(rect)};
}
