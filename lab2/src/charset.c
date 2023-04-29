#include <stdlib.h>

#include <GL/gl.h>

#include "charset.h"
#include "types.h"
#include "image.h"
#include "texture.h"


Charset default_charset;


void charsetLoad(Charset *charset, const char *file_name)
{
    if (charset->texture.id) return;  /* Error: charset already loaded. */

    Image image = {};
    imageLoad(&image, file_name);

    textureLoadFromImage(&charset->texture, &image);

    charset->char_width_array = calloc(
        256, sizeof(*charset->char_width_array)
    );

    charset->char_cell_size = image.size.width >> 4;

    for (int ch = 0; ch < 256; ++ch) {
        _coord_t x = (ch & 15) * charset->char_cell_size;
        _coord_t y = (ch >> 4) * charset->char_cell_size;

        _rgba_channel_t alpha = 0;
        for (int j = x + charset->char_cell_size - 1; j > x; --j) {
            for (int i = y; i < y + charset->char_cell_size; ++i) {
                alpha = image.data[image.channels_count * (
                    image.size.width * i + j
                ) + 3];

                if (alpha > 0) {
                    charset->char_width_array[ch] = (j - x);
                    break;
                }
            }
            if (alpha > 0) break;
        }
    }

    charset->char_width_array[' '] = charset->char_cell_size / 4;

    imageFree(&image);
}

void charsetFree(Charset *charset)
{
    textureFree(&charset->texture);

    free(charset->char_width_array);
    *charset = (Charset){};
}
