#include "ke_window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
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

    processmousemovement(xoffset, yoffset);
}        
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){

}

GLFWwindow* createWindow(int width, int height, const char* title){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL){
        printf("Failed to create GLFW window");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window,  mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    return window;
}
