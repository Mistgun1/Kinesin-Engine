#ifndef KE_MATH_H
#define KE_MATH_H

#include <stdlib.h>

#define PI 3.14159265358979323846

typedef struct vec2 {
    float x;
    float y;
} vec2;

typedef struct vec3 {
    float x;
    float y;
    float z;
} vec3;

typedef struct vec4 {
    float x;
    float y;
    float z;
    float w;
} vec4;

typedef struct mat4 {
    float m[16];
} mat4;

float radians(float degrees);

vec2 vec2_create(float x, float y);
vec3 vec3_create(float x, float y, float z);
vec4 vec4_create(float x, float y, float z, float w);
mat4 mat4_identity_create(void);

vec2 vec2_add(vec2 a, vec2 b);
vec3 vec3_add(vec3 a, vec3 b);
vec4 vec4_add(vec4 a, vec4 b);

vec2 vec2_sub(vec2 a, vec2 b);
vec3 vec3_sub(vec3 a, vec3 b);
vec4 vec4_sub(vec4 a, vec4 b);

float vec2_dot(vec2 a, vec2 b);
float vec3_dot(vec3 a, vec3 b);
float vec4_dot(vec4 a, vec4 b);

float vec2_length(vec2 a);
float vec3_length(vec3 a);
float vec4_length(vec4 a);

vec2 vec2_normalize(vec2 a);
vec3 vec3_normalize(vec3 a);
vec4 vec4_normalize(vec4 a);

mat4 mat4_translate_create(vec3* v);
mat4 mat4_rotate_x_create(float angle);
mat4 mat4_rotate_y_create(float angle);
mat4 mat4_rotate_z_create(float angle);
mat4 mat4_rotate_create(float angle, vec3* v);
mat4 mat4_scale_create(vec3* v);

vec4 mat4_mul_vec4(mat4 m, vec4 v);
mat4 mat4_mul_mat4(mat4 a, mat4 b);

mat4 mat4_mul(int n, ...);

#endif

