#include "ke_math.h"
#include <math.h>

vec2 vec2_create(float x, float y) {
    vec2 v;
    v.x = x;
    v.y = y;
    return v;
}

vec3 vec3_create(float x, float y, float z) {
    vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

vec4 vec4_create(float x, float y, float z, float w) {
    vec4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

mat4 mat4_identity_create() {
    mat4 m = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    return m;
}

vec2 vec2_add(vec2 a, vec2 b) {
    vec2 v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    return v;
}

vec3 vec3_add(vec3 a, vec3 b) {
    vec3 v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    v.z = a.z + b.z;
    return v;
}

vec4 vec4_add(vec4 a, vec4 b) {
    vec4 v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    v.z = a.z + b.z;
    v.w = a.w + b.w;
    return v;
}

vec2 vec2_sub(vec2 a, vec2 b) {
    vec2 v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    return v;
}

vec3 vec3_sub(vec3 a, vec3 b) {
    vec3 v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    return v;
}

vec4 vec4_sub(vec4 a, vec4 b) {
    vec4 v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    v.w = a.w - b.w;
    return v;
}

float vec2_dot(vec2 a, vec2 b) {
    return a.x * b.x + a.y * b.y;
}

float vec3_dot(vec3 a, vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float vec4_dot(vec4 a, vec4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float vec2_length(vec2 v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

float vec3_length(vec3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float vec4_length(vec4 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

vec2 vec2_normalize(vec2 v) {
    float len = vec2_length(v);
    vec2 norm;
    norm.x = v.x / len;
    norm.y = v.y / len;
    return norm;
}

vec3 vec3_normalize(vec3 v) {
    float len = vec3_length(v);
    vec3 norm;
    norm.x = v.x / len;
    norm.y = v.y / len;
    norm.z = v.z / len;
    return norm;
}

vec4 vec4_normalize(vec4 v) {
    float len = vec4_length(v);
    vec4 norm;
    norm.x = v.x / len;
    norm.y = v.y / len;
    norm.z = v.z / len;
    norm.w = v.w / len;
    return norm;
}

mat4 mat4_translate(vec3* v){
    mat4 t = mat4_identity_create();
    t.m[3] = v->x;
    t.m[7] = v->y;
    t.m[11] = v->z;
    return t;
}

mat4 mat4_rotate_x(float angle){
    mat4 r = mat4_identity_create();
    float c = cosf(angle);
    float s = sinf(angle);
    r.m[5] = c;
    r.m[6] = -s;
    r.m[9] = s;
    r.m[10] = c;
    return r;
}

mat4 mat4_rotate_y(float angle){
    mat4 r = mat4_identity_create();
    float c = cosf(angle);
    float s = sinf(angle);
    r.m[0] = c;
    r.m[2] = s;
    r.m[8] = -s;
    r.m[10] = c;
    return r;
}

mat4 mat4_rotate_z(float angle){
    mat4 r = mat4_identity_create();
    float c = cosf(angle);
    float s = sinf(angle);
    r.m[0] = c;
    r.m[1] = -s;
    r.m[4] = s;
    r.m[5] = c;
    return r;
}

