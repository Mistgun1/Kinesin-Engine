#ifndef KE_TEXTURE_H
#define KE_TEXTURE_H

#include "stb_image.h"
#include "se_gl.h"
#include <stdbool.h>

#define TEXTURE_PATH "../resources/textures/"

void load_jpg_texture(unsigned int *texture, char *filename, bool flip);
void load_png_texture(unsigned int *texture, char *filename, bool flip);

#endif
