#ifndef SHADER_H
#define SHADER_H
#define SHADER_PATH "../resources/shaders/"

#include <stdbool.h>
#include "ke_math.h"
#include "se_gl.h"
#include <stdbool.h>
#include <stdarg.h>
#include "ke_math.h"
#include <stdlib.h>
#include <GLFW/glfw3.h>

typedef struct Shader{
    unsigned int ID;
    char *vertexFileName;
    char *fragmentFileName;
}Shader;

typedef struct material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}material;

typedef struct light{
    vec3 position;
    vec3 color;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
}light;

void initShader(Shader *shader);
void useShader(Shader *shader);
void setBool(Shader *shader, char *name, bool value);
void setInt(Shader *shader, char *name, int value);
void setFloat(Shader *shader, char *name, float value);
void setVec2(Shader *shader, char *name, vec2 value);
void setVec3(Shader *shader, char *name, vec3 value);
void setMat4(Shader *shader, char *name, mat4 value);
material defaultMaterial(void);
light defaultLight(void);
void setMaterial(Shader *shader, material material);
void setLight(Shader *shader, light light);
#define setMaterial(...)   vrg(setMaterial, __VA_ARGS__)
#define setMaterial1(n)    setMaterialX(n, defaultMaterial())
#define setMaterial2(n, m) setMaterialX(n, m)
void setMaterialX(Shader *shader, material Material);
#define setLight(...)   vrg(setLight, __VA_ARGS__)
#define setLight1(n)    setLightX(n, defaultLight())
#define setLight2(n, m) setLightX(n, m)
void setLightX(Shader *shader, light Light);




#endif
