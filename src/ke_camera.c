#include "ke_camera.h"
#include "ke_math.h"
#include <math.h>

mat4 mat4_perspective(float fov, float aspectRatio, float near, float far){
    mat4 perspective = mat4_identity();
    
    const float DEG2RAD = PI / 180.0f;
    float tangent = tanf(fov * DEG2RAD / 2.0f);
    float top = near * tangent;
    float right = top * aspectRatio;

    perspective.m[0] = near / right;
    perspective.m[5] = near / top;
    perspective.m[10] = -(far + near) / (far - near);
    perspective.m[11] = -1.0f;
    perspective.m[14] = -(2.0f * far * near) / (far - near);
    return perspective;
}

mat4 mat4_orthographic(float left, float right, float bottom, float top, float near, float far){
    mat4 orthographic = mat4_identity();

    orthographic.m[0] = 2.0f / (right - left);
    orthographic.m[3] = -(right + left) / (right - left);
    orthographic.m[5] = 2.0f / (top - bottom);
    orthographic.m[7] = -(top + bottom) / (top - bottom);
    orthographic.m[10] = -2.0f / (far - near);
    orthographic.m[11] = -(far + near) / (far - near);
    orthographic.m[14] = 1.0f;
    return orthographic;
}

mat4 mat4_look_at(vec3 position, vec3 target, vec3 up){
    vec3 direction = vec3_normalize(vec3_sub(target, position));
    vec3 right = vec3_normalize(vec3_cross(up, direction));
   
    vec3 negative_position = vec3_negate(position);
    mat4 cameraPosition = mat4_translate(&negative_position);

    mat4 cameraRotation = mat4_identity();
    cameraRotation.m[0] = right.x;
    cameraRotation.m[1] = right.y;
    cameraRotation.m[2] = right.z;
    cameraRotation.m[4] = up.x;
    cameraRotation.m[5] = up.y;
    cameraRotation.m[6] = up.z;
    cameraRotation.m[8] = direction.x;
    cameraRotation.m[9] = direction.y;
    cameraRotation.m[10] = direction.z;

    return mat4_mul_mat4(cameraPosition, cameraRotation);
}

