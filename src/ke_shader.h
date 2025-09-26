#ifndef SHADER_H
#define SHADER_H
#define SHADER_PATH "../resources/shaders/"

#include <stdbool.h>
#include "ke_math.h"
#include <stdbool.h>
#include <GLFW/glfw3.h>

typedef struct Shader{
    unsigned int ID;
    char *vertexFileName;
    char *fragmentFileName;
}Shader;

void initShader(Shader *shader);
void useShader(Shader *shader);
void setBool(Shader *shader, char *name, bool value);
void setInt(Shader *shader, char *name, int value);
void setFloat(Shader *shader, char *name, float value);
void setVec2(Shader *shader, char *name, vec2 value);
void setVec3(Shader *shader, char *name, vec3 value);

#endif
