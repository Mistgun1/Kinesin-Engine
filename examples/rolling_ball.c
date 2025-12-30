#include <stdio.h>
#include <GLFW/glfw3.h>
#include "se_gl.h"
#include "ke_window.h"
#include "ke_shader.h"
#include "ke_shapes.h"
#include "ke_math.h"
#include "ke_renderer.h"

void processInput(GLFWwindow* window);

int main(int argc, char **argv){
    
    glfwInit();
    GLFWwindow* window = createWindow(800, 600, "Rolling Ball");
    
    se_init_opengl();

    Shader shader;
    shader.vertexFileName = "shaders/colorful.vs";
    shader.fragmentFileName = "shaders/colorful.fs";
    initShader(&shader);

    shape* ball = generate_sphere(vec3_create(1.0f, 0.f, 0.f), 20, 20);
    shape* floor = generate_square(vec3_create(0.f, 0.f, 0.f));


    render_mesh(ball);

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)){

        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    }
    return 0;
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}
