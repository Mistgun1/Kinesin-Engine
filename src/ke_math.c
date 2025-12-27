#include "ke_math.h"
#include <stdarg.h>
#include <math.h>


float radians(float degrees) {
    return degrees * PI / 180;
}

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

mat4 mat4_identity() {
    mat4 m = {1, 0, 0, 0,
              0, 1, 0, 0,
              0, 0, 1, 0,
              0, 0, 0, 1};
    return m;
}

vec2 vec2_negate(vec2 v) {
    vec2 result;
    result.x = -v.x;
    result.y = -v.y;
    return result;
}

vec3 vec3_negate(vec3 v) {
    vec3 result;
    result.x = -v.x;
    result.y = -v.y;
    result.z = -v.z;
    return result;
}

vec4 vec4_negate(vec4 v) {
    vec4 result;
    result.x = -v.x;
    result.y = -v.y;
    result.z = -v.z;
    result.w = -v.w;
    return result;
}

vec2 vec2_mul_float(vec2 v, float f) {
    vec2 result;
    result.x = v.x * f;
    result.y = v.y * f;
    return result;
}

vec3 vec3_mul_float(vec3 v, float f) {
    vec3 result;
    result.x = v.x * f;
    result.y = v.y * f;
    result.z = v.z * f;
    return result;
}

vec4 vec4_mul_float(vec4 v, float f) {
    vec4 result;
    result.x = v.x * f;
    result.y = v.y * f;
    result.z = v.z * f;
    result.w = v.w * f;
    return result;
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

vec4 vec3_to_vec4(vec3 v) {
    vec4 result;
    result.x = v.x;
    result.y = v.y;
    result.z = v.z;
    result.w = 1.0f;
    return result;
}

vec3 vec4_to_vec3(vec4 v) {
    vec3 result;
    result.x = v.x;
    result.y = v.y;
    result.z = v.z;
    return result;
}

mat4 mat4_translate(vec3* v){
    mat4 t = mat4_identity();
    t.m[3] = v->x;
    t.m[7] = v->y;
    t.m[11] = v->z;
    return t;
}

mat4 mat4_rotate_x(float angle){
    mat4 r = mat4_identity();
    float c = cosf(angle);
    float s = sinf(angle);
    r.m[5] = c;
    r.m[6] = -s;
    r.m[9] = s;
    r.m[10] = c;
    return r;
}

mat4 mat4_rotate_y(float angle){
    mat4 r = mat4_identity();
    float c = cosf(angle);
    float s = sinf(angle);
    r.m[0] = c;
    r.m[2] = s;
    r.m[8] = -s;
    r.m[10] = c;
    return r;
}

mat4 mat4_rotate_z(float angle){
    mat4 r = mat4_identity();
    float c = cosf(angle);
    float s = sinf(angle);
    r.m[0] = c;
    r.m[1] = -s;
    r.m[4] = s;
    r.m[5] = c;
    return r;
}

mat4 mat4_rotate(float angle, vec3* axis){
    mat4 r = mat4_identity();
    float c = cosf(angle);
    float s = sinf(angle);
    r.m[0] = c + axis->x * axis->x * (1 - c);
    r.m[1] = axis->x * axis->y * (1 - c) - axis->z * s;
    r.m[2] = axis->x * axis->z * (1 - c) + axis->y * s;
    r.m[4] = axis->y * axis->x * (1 - c) + axis->z * s;
    r.m[5] = c + axis->y * axis->y * (1 - c);
    r.m[6] = axis->y * axis->z * (1 - c) - axis->x * s;
    r.m[8] = axis->z * axis->x * (1 - c) - axis->y * s;
    r.m[9] = axis->z * axis->y * (1 - c) + axis->x * s;
    r.m[10] = c + axis->z * axis->z * (1 - c);
    return r;
}


mat4 mat4_scale(vec3* v){
    mat4 s = mat4_identity();
    s.m[0] = v->x;
    s.m[5] = v->y;
    s.m[10] = v->z;
    return s;
}

vec4 mat4_mul_vec4(mat4 m, vec4 v){
    vec4 result;
    result.x = m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z + m.m[3] * v.w;
    result.y = m.m[4] * v.x + m.m[5] * v.y + m.m[6] * v.z + m.m[7] * v.w;
    result.z = m.m[8] * v.x + m.m[9] * v.y + m.m[10] * v.z + m.m[11] * v.w;
    result.w = m.m[12] * v.x + m.m[13] * v.y + m.m[14] * v.z + m.m[15] * v.w;
    return result;
}

mat4 mat4_mul_mat4(mat4 a, mat4 b) {
    mat4 R;
    for(int row=0; row<4; row++){
        for(int col=0; col<4; col++){
            float sum = 0.0f;
            for(int k=0; k<4; k++){
                sum += a.m[row + 4*k] * b.m[k + 4*col];
            }
            R.m[row + 4*col] = sum;
        }
    }
    return R;
}

mat4 mat4_transpose(mat4 m){
    mat4 t;
    for(int row=0; row<4; row++){
        for(int col=0; col<4; col++){
            t.m[row + 4*col] = m.m[col + 4*row];
        }
    }
    return t;
}


mat4 mat4_mul(int n, ...){
    va_list args;
    mat4 result = mat4_identity();
    va_start(args, n);
    for(int i = n - 1; i >= 0; i--){
        result = mat4_mul_mat4(result, va_arg(args, mat4));
    }
    va_end(args);
    return result;
}

vec3 vec3_cross(vec3 a, vec3 b) {
    vec3 c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
    return c;
}
