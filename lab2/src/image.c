#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include "image.h"


void imageLoad(Image *image, const char *file_name)
{
    if (image->data) return;  /* Error: image data is not empty. */

    image->data = stbi_load(
        file_name,
        &(image->size.width),
        &(image->size.height),
        &(image->channels_count),
        0
    );
}

void imageFree(Image *image)
{
    if (!image->data) return;  /* Error: image is not loaded. */

    stbi_image_free(image->data);

    *image = (Image){};
}
