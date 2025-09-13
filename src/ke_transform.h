#ifndef KE_TRANSFORM_H
#define KE_TRANSFORM_H

#include "ke_math.h"

void translate_vec3(mat4 *m, vec3 *v);
void translate_xyz(mat4 *m, float x, float y, float z);

void rotate_x(mat4 *m, float angle);
void rotate_y(mat4 *m, float angle);
void rotate_z(mat4 *m, float angle);
void rotate(mat4 *m, float angle, vec3 *axis);

void scale_vec3(mat4 *m, vec3 *v);
void scale_xyz(mat4 *m, float x, float y, float z);

#endif
