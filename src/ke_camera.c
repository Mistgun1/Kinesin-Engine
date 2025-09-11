#include "ke_camera.h"
#include "ke_math.h"
#include <math.h>

mat4 mat4_perspective(float fov, float aspectRatio, float front, float back){
    mat4 perspective = mat4_identity_create();
    
    const float DEG2RAD = PI / 180.0f;
    float tangent = tanf(fov * DEG2RAD / 2.0f);
    float top = front * tangent;
    float right = top * aspectRatio;

    perspective.m[0] = front / right;
    perspective.m[5] = front / top;
    perspective.m[10] = -(back + front) / (back - front);
    perspective.m[11] = -1.0f;
    perspective.m[14] = -(2.0f * back * front) / (back - front);
    return perspective;
}


