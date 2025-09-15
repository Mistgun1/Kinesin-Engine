#ifndef KE_WINDOW_H
#define KE_WINDOW_H

#include <GLFW/glfw3.h>

void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* createWindow(int width, int height, const char* title);

#endif
