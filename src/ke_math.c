#include "re_math.h"
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

// mat4 create  


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


