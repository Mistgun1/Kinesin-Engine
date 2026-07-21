#include "ke_input.h"

void updateCameraVectors(Camera* camera)
    {
        // calculate the new Front vector
        vec3 front;
        front.x = cos(radians(camera->yaw)) * cos(radians(camera->pitch));
        front.y = sin(radians(camera->pitch));
        front.z = sin(radians(camera->yaw)) * cos(radians(camera->pitch));
        camera->target = vec3_normalize(front);
        // also re-calculate the Right and Up vector
    }


void ProcessMouseMovement(Camera* camera, float xoffset, float yoffset, GLboolean constrainPitch ){
 
        xoffset *= camera->sensitivity;
        yoffset *= camera->sensitivity;

        camera->yaw   += xoffset;
        camera->pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch)
        {
            if (camera->pitch > 89.0f)
                camera->pitch = 89.0f;
            if (camera->pitch < -89.0f)
                camera->pitch = -89.0f;
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors(camera);
}

void mouse_callback(GLFWwindow* window, double xposin, double yposin){

    float xpos = (float)xposin;
    int width, height;
    
    glfwGetWindowSize(window, &width, &height);
    float ypos = (float)yposin;

    bool firstmouse = true;

    float lastx = width / 2.0f;
    float lasty = height / 2.0f;
    if (firstmouse)
    {
        lastx = xpos;
        lasty = ypos;
        firstmouse = false;
    }

    float xoffset = xpos - lastx;
    float yoffset = lasty - ypos; // reversed since y-coordinates go from bottom to top
    lastx = xpos;
    lasty = ypos;
    
    outputOffset(xoffset, yoffset);
    processmousemovement(&camera, xoffset, yoffset);
}


void initInput(GLFWwindow* window){
    glfwSetCursorPosCallback(window,  mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
}


