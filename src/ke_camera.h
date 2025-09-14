#ifndef KE_CAMERA_H
#define KE_CAMERA_H

#include "ke_math.h"

mat4 mat4_perspective(float fov, float aspectRatio, float front, float back);
mat4 mat4_orthographic(float left, float right, float bottom, float top, float near, float far);
mat4 mat4_look_at(vec3 position, vec3 target, vec3 up);

#endif
