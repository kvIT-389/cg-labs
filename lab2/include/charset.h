#ifndef CHARSET_H_INCLUDED_
#define CHARSET_H_INCLUDED_


#include "types.h"
#include "texture.h"


/**
 * Structure which stores @a texture of some charset
 * and related to it
 * size of character cell specified by @a char_cell_size
 * and array of characters widths specified by @a char_width_array.
 */
typedef struct charset
{
    Texture texture;

    _size_t char_cell_size;
    _size_t *char_width_array;
} Charset;


extern Charset default_charset;


/**
 * Loads charset from the file specified by @a file_name
 * and saves its data to @a charset.
 * 
 * File with charset must be a square with a side length equal
 * to the power of 2 and contain 256 characters in 16x16 grid.
 */
void charsetLoad(Charset *charset, const char *file_name);

/**
 * Deletes loaded charset specified by @a charset.
 */
void charsetFree(Charset *charset);


#endif  /* CHARSET_H_INCLUDED_ */
