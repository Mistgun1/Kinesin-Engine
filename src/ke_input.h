#ifndef KE_INPUT_H
#define KE_INPUT_H

#include <GLFW/glfw3.h>
#include "ke_camera.h"

void updateCameraVectors(Camera* camera);
void ProcessMouseMovement(Camera* camera, float xoffset, float yoffset, GLboolean constrainPitch );
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void initInput(GLFWwindow* window);


//void processKeyboard(GLFWwindow* window);
void processMouse(GLFWwindow* window, Camera camera);
//void processScroll(GLFWwindow* window);

#endif
