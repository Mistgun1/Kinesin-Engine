#include "ke_shader.h"
#include "ke_math.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>
#include "se_gl.h"

void initShader(Shader *shader){

    //copying the shaders from the files
    char fragmentPath[250]; 
    char vertexPath[250];

    sprintf(fragmentPath, "%s%s", SHADER_PATH, shader->fragmentFileName);
    sprintf(vertexPath, "%s%s", SHADER_PATH, shader->vertexFileName);

    FILE *fragmentShaderFile = fopen(fragmentPath, "r");
    FILE *vertexShaderFile = fopen(vertexPath, "r");

    setvbuf(fragmentShaderFile, NULL, _IOFBF, BUFSIZ);
    char fragmentBuffer[BUFSIZ];
    fread(fragmentBuffer, 1, BUFSIZ, fragmentShaderFile);
    const char *fragmentShaderCode = fragmentBuffer;

    setvbuf(vertexShaderFile, NULL, _IOFBF, BUFSIZ);
    char vertexBuffer[BUFSIZ - 2];
    fread(vertexBuffer, 1, BUFSIZ - 2, vertexShaderFile);
    const char *vertexShaderCode = vertexBuffer;

    fclose(fragmentShaderFile);
    fclose(vertexShaderFile);

    int vertex, fragment;
    int success;
    char infoLog[512];

    
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        printf("ERROR::VERTEX::%s\n", infoLog);
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        printf("ERROR::FRAGMENT::%s\n", infoLog);
    }
   
    shader->ID = glCreateProgram();
    glAttachShader(shader->ID, vertex);
    glAttachShader(shader->ID, fragment);
    glLinkProgram(shader->ID);
    glGetProgramiv(shader->ID, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shader->ID, 512, NULL, infoLog);
        printf("ERROR::PROGRAM::%s\n", infoLog);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void useShader(Shader *shader){
    glUseProgram(shader->ID);
}

void setBool(Shader *shader, char *name, bool value){
    glUniform1i(glGetUniformLocation(shader->ID, name), (int)value);
}

void setFloat(Shader *shader, char *name, float value){
    glUniform1i(glGetUniformLocation(shader->ID, name), value);
}

void setInt(Shader *shader, char *name, int value){
    glUniform1i(glGetUniformLocation(shader->ID, name), value);
}

void setVec2(Shader *shader, char *name, vec2 value){
    glUniform2f(glGetUniformLocation(shader->ID, name), value.x, value.y);
}

void setVec3(Shader *shader, char *name, vec3 value){
    glUniform3f(glGetUniformLocation(shader->ID, name), value.x, value.y, value.z);
}
