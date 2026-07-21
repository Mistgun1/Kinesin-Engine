#ifndef KE_CAMERA_H
#define KE_CAMERA_H

#include "ke_math.h"
#include <stdbool.h>
#include <math.h>
#include <GLFW/glfw3.h>
#include "ke_window.h"


typedef struct Camera{
    vec3 position;
    vec3 target;
    vec3 up;
    
    float yaw;
    float pitch;
    float roll; 
    float speed;
    float sensitivity;
    float zoom;
}Camera; 

Camera defaultCamera = {
    {0.0f , 0.0f, 0.0f},
    {0.0f , 0.0f, -1.0f},
    { 0.0f, 1.0f, 0.0f},
    -90.0f,
    0.0f,
    0.0f,
    1.0f,
    0.1f,
    45.0f
};

mat4 mat4_perspective(float fov, float aspectRatio, float front, float back);
mat4 mat4_orthographic(float left, float right, float bottom, float top, float near, float far);
mat4 mat4_look_at(Camera* camera);


// camera movement
//void processKeyboard(Camera* camera);
//void processMouse(Camera* camera);
//void processScroll(Camera* camera);


#endif
