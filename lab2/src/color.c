#include <GL/gl.h>

#include "color.h"


const Color white =      {0xff, 0xff, 0xff, 0xff};
const Color gainsboro =  {0xdc, 0xdc, 0xdc, 0xff};
const Color lightgray =  {0xd3, 0xd3, 0xd3, 0xff};
const Color silver =     {0xc0, 0xc0, 0xc0, 0xff};
const Color darkgray =   {0xa9, 0xa9, 0xa9, 0xff};
const Color gray =       {0x80, 0x80, 0x80, 0xff};
const Color slategray =  {0x70, 0x80, 0x90, 0xff};
const Color dimgray =    {0x69, 0x69, 0x69, 0xff};


void setColor(const Color *color)
{
    if (!color) return;

    glColor4ubv(color->channels);
}