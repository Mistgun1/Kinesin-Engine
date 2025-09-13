#include "ke_transform.h"
#include "ke_math.h"

void translate_vec3(mat4 *m, vec3 *v){
    mat4 t = mat4_translate_create(v);
    *m = mat4_mul_mat4(*m, t);
}

void translate_xyz(mat4 *m, float x, float y, float z){
    vec3 v = {x, y, z};
    mat4 t = mat4_translate_create(&v);
    *m = mat4_mul_mat4(*m, t);
}

void rotate_x(mat4 *m, float angle){
    mat4 r = mat4_rotate_x_create(angle);
    *m = mat4_mul_mat4(*m, r);
}

void rotate_y(mat4 *m, float angle){
    mat4 r = mat4_rotate_y_create(angle);
    *m = mat4_mul_mat4(*m, r);
}

void rotate_z(mat4 *m, float angle){
    mat4 r = mat4_rotate_z_create(angle);
    *m = mat4_mul_mat4(*m, r);
}

void rotate(mat4 *m, float angle, vec3 *axis){
    mat4 r = mat4_rotate_create(angle, axis);
    *m = mat4_mul_mat4(*m, r);
}

void scale_vec3(mat4 *m, vec3 *v){
    mat4 s = mat4_scale_create(v);
    *m = mat4_mul_mat4(*m, s);
}

void scale_xyz(mat4 *m, float x, float y, float z){
    vec3 v = {x, y, z};
    mat4 s = mat4_scale_create(&v);
    *m = mat4_mul_mat4(*m, s);
}


