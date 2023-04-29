#ifndef IMAGE_H_INCLUDED_
#define IMAGE_H_INCLUDED_


#include "types.h"
#include "size.h"


typedef struct image
{
    _rgba_channel_t *data;

    Size size;
    GLint channels_count;
} Image;


/**
 * Loads image from the file specified by @a file_name
 * and saves its data to the @a image.
 */
void imageLoad(Image *image, const char *file_name);

/**
 * Deletes loaded image specified by @a texture.
 */
void imageFree(Image *image);


#endif  /* IMAGE_H_INCLUDED_ */
