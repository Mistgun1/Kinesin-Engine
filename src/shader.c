#include "shader.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void initShader(Shader *shader){

    char* fragmentPath; 
    char* vertexPath;

    sprintf(fragmentPath, "%s%s", SHADER_PATH, shader->fragmentFileName);
    sprintf(vertexPath, "%s%s", SHADER_PATH, shader->vertexFileName);

    FILE *fragmentShaderFile = fopen(fragmentPath, "r");
    FILE *vertexShaderFile = fopen(vertexPath, "r");

    int fragmentFileSize = fseek(fragmentShaderFile, 0, SEEK_END);
    char fragmentBuffer[fragmentFileSize];
    char *fragmentShaderCode = fgets(fragmentBuffer, sizeof(fragmentBuffer), fragmentShaderFile);

    int vertexFileSize = fseek(vertexShaderFile, 0, SEEK_END);
    char vertexBuffer[vertexFileSize];
    char *vertexShaderCode = fgets(vertexBuffer, sizeof(vertexBuffer), vertexShaderFile);

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
