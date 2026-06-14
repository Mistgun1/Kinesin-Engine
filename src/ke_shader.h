#ifndef SHADER_H
#define SHADER_H
#define SHADER_PATH "../resources/shaders/"

#include <stdbool.h>
#include "ke_math.h"
#include "se_gl.h"
#include <stdbool.h>
#include "ke_math.h"
#include <stdlib.h>
#include <GLFW/glfw3.h>

typedef struct Shader{
    unsigned int ID;
    char *vertexFileName;
    char *fragmentFileName;
}Shader;

typedef struct Material{
    vec3 diffuse;
    vec3 sepcular;
    float shininess;
}Material;

typedef struct Light{
    vec3 position;
    vec3 color;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
}Light;



#define vec3_c(v, _x, _y, _z) v.x = _x; v.y = _y; v.z = _z
//Default Material
vec3_c(vec3 diffuseMaterial, 1.0f, 1.0f, 1.0f);
vec3 specular; 
float shininess = 1.0f;

//Default Light


Material defaultMaterial();
Light defaultLight();

void initShader(Shader *shader);
void useShader(Shader *shader);
void setBool(Shader *shader, char *name, bool value);
void setInt(Shader *shader, char *name, int value);
void setFloat(Shader *shader, char *name, float value);
void setVec2(Shader *shader, char *name, vec2 value);
void setVec3(Shader *shader, char *name, vec3 value);
void setMat4(Shader *shader, char *name, mat4 value);
void setMaterial(Shader *shader, Material material);
void setLight(Shader *shader, Light light);

#endif
