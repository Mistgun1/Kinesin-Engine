#include <stdio.h>
#include "se_gl.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <unistd.h>
#include "shader.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);  
void processInput(GLFWwindow *window);

int main(void){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    se_init_opengl();

    Shader colorful;
    colorful.vertexFileName = "colorful.vs";
    colorful.fragmentFileName = "colorful.fs";

    initShader(&colorful);

    //const char* vertexShaderSource = "#version 420 core\n"
    //    "layout (location = 0) in vec3 aPos;\n"
    //    "void main()\n"
    //    "{\n"
    //    "gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
    //    "}\0";
    //unsigned int vertexShader;
    //vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //glShaderSource(vertexShader, 1 ,&vertexShaderSource, NULL);
    //glCompileShader(vertexShader);

    //const char* fragmentShaderSource = "#version 420 core\n"
    //    "out vec4 FragColor;\n"
    //    "void main ()\n"
    //    "{\n"
    //    "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    //    "}\0";
    //unsigned int fragmentShader;
    //fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    //glCompileShader(fragmentShader);


    //// check shader compilation
    //int success;
    //char infoLog[512];
    //glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    //if (!success){
    //    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    //    printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    //}

    //glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    //if (!success){
    //    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //    printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    //}

    //unsigned int shaderProgram;
    //shaderProgram = glCreateProgram();
    //glAttachShader(shaderProgram, vertexShader);
    //glAttachShader(shaderProgram, fragmentShader);
    //glLinkProgram(shaderProgram);
    //glDeleteShader(vertexShader);
    //glDeleteShader(fragmentShader);

    float vertices[] = {
        0.5f,  0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
       -0.5f,  0.5f, 0.0f
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    //VAO and VBO
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
   
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    //glBindVertexArray(0);

    while(!glfwWindowShouldClose(window)){
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        useShader(&colorful);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();   
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}  
