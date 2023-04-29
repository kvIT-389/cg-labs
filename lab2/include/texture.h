#ifndef TEXTURE_H_INCLUDED_
#define TEXTURE_H_INCLUDED_


#include "types.h"
#include "size.h"
#include "image.h"


/**
 * Structure which stores @a id of some texture
 * and its size in pixels.
 * 
 * if @a id is equals to zero texture is not associated
 * with any texture on GPU.
 */
typedef struct texture
{
    _texture_id_t id;

    Size size;
} Texture;


extern Texture test_texture;


/**
 * Loads texture from the file specified by @a file_name
 * and saves associated with it id and size to the @a texture.
 */
void textureLoadFromFile(Texture *texture, const char *file_name);

/**
 * Loads texture using data of the given image specified by @a image
 * and saves associated with it id and size to the @a texture.
 */
void textureLoadFromImage(Texture *texture, const Image *image);

/**
 * Deletes loaded texture specified by @a texture.
 */
void textureFree(Texture *texture);


#endif  /* TEXTURE_H_INCLUDED_ */
