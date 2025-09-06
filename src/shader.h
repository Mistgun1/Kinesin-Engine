#ifndef SHADER_H
#define SHADER_H

#include "se_gl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Shader{
    unsigned int ID;
    char *vertexPath;
    char *fragmentPath;
}Shader;

void initShader(Shader *shader);
void useShader(Shader *shader);
void setBool(Shader *shader, char *name, bool value);
void setInt(Shader *shader, char *name, int value);
void setFloat(Shader *shader, char *name, float value);

#endif
