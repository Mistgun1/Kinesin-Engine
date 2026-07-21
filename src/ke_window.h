#ifndef KE_WINDOW_H
#define KE_WINDOW_H

#include <stdio.h>  
#include <GLFW/glfw3.h>
#include <stdbool.h>

void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xposin, double yposin);        
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
GLFWwindow* createWindow(int width, int height, const char* title);

#endif
