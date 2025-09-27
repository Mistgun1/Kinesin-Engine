#include "ke_texture.h"

void load_jpg_texture(unsigned int *texture, char *filename, bool flip)
{
    if (flip)
    {
        stbi_set_flip_vertically_on_load(true);
    }
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    int width, height, nrChannels;
    char full_texture_path[256];
    sprintf(full_texture_path, "%s%s",TEXTURE_PATH , filename);
    unsigned char *data = stbi_load(full_texture_path, &width, &height, &nrChannels, 0);
    if (data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        printf("Failed to load texture image %s\n", filename);
    }
    stbi_image_free(data);
    stbi_set_flip_vertically_on_load(false);
}

void load_png_texture(unsigned int *texture, char *filename, bool flip)
{
    if (flip)
    {
        stbi_set_flip_vertically_on_load(true);
    }
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    int width, height, nrChannels;
    char full_texture_path[256];
    sprintf(full_texture_path, "%s%s",TEXTURE_PATH , filename);
    unsigned char *data = stbi_load(full_texture_path, &width, &height, &nrChannels, 0);
    if (data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        printf("Failed to load texture image %s\n", filename);
    }
    stbi_image_free(data);
    stbi_set_flip_vertically_on_load(false);
}
