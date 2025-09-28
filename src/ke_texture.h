#ifndef KE_TEXTURE_H
#define KE_TEXTURE_H

#include "stb_image.h"
#include "se_gl.h"
#include <stdbool.h>

#define TEXTURE_PATH "../resources/textures/"

unsigned int load_jpg_texture(char *filename, bool flip);
unsigned int load_png_texture(char *filename, bool flip);

#endif
