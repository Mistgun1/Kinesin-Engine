#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "ke_math.h"
#include "ke_physics.h"
#include "ke_window.h"
#include "se_gl.h"
#include "ke_camera.h"
#include "ke_shader.h"
#include "ke_shapes.h"
#include "ke_transform.h"
#include "stb_image.h"


void processInput(GLFWwindow* window);


float deltaTime = 0.0f;
float previousTime = 0.0f;

vec3 cameraPosition;
vec3 cameraTarget;
vec3 cameraUp;

int main(int argc, char *argv[]){
   
    cameraPosition = vec3_create(0.0f, 0.0f, 0.0f);
    cameraTarget = vec3_create(0.0f, 0.0f, 1.0f);
    cameraUp = vec3_create(0.0f, 1.0f, 0.0f);
    
    glfwInit();
    GLFWwindow* window = createWindow(1920, 1080, "eath moon");
    se_init_opengl();

    Shader shader;
    shader.vertexFileName = "colorful.vs";
    shader.fragmentFileName = "colorful.fs";
    initShader(&shader);
    
    unsigned int earthTexture, moonTexture;
    glGenTextures(1, &earthTexture);
    glBindTexture(GL_TEXTURE_2D, earthTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("../resources/textures/earth.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load earth texture\n");
    }
    stbi_image_free(data); 

    glGenTextures(1, &moonTexture);
    glBindTexture(GL_TEXTURE_2D, moonTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    data = stbi_load("../resources/textures/moon.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load moon texture\n");
    }
    stbi_image_free(data);


    vec3 white = vec3_create(1.0f, 1.0f, 1.0f);
    shape* earth = generate_sphere(white , 200, 200);
    shape* moon = generate_sphere(white , 60, 60);

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * earth->vertex_count *11, earth->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * earth->index_count, earth->indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8 * sizeof(float)));
    glEnableVertexAttribArray(3);

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)){
        processInput(window);
        glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, earthTexture);
        useShader(&shader);
        
        mat4 model = mat4_identity();
        scale_xyz(&model, 0.1f, 0.1f, 0.1f);
        
        //vec3 rotation_axis = vec3_create(0.5f, 1.0f, 0.0f);
        //rotate_vec3(&model, (float)glfwGetTime() * radians(55.0f), &rotation_axis);

        mat4 view = mat4_look_at(cameraPosition, cameraTarget, cameraUp);
    
        mat4 projection = mat4_perspective(45.0f, 1920.0f/1080.0f, 0.1f, 100.0f); 
    
        int modelLocation = glGetUniformLocation(shader.ID, "model");
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, model.m);
        int viewLocation = glGetUniformLocation(shader.ID, "view");
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, view.m);
        int projectionLocation = glGetUniformLocation(shader.ID, "projection");
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, projection.m);

        vec3 lightPosition = vec3_create(20.0f, 0.0f, 12.0f);
        vec3 rotation_axis = vec3_create(0.0f, 1.0f, 0.0f);
        mat4 light_rotation = mat4_rotate((float)glfwGetTime() * radians(55.0f), &rotation_axis);
        vec4 lightPositionVec4 = vec3_to_vec4(lightPosition);
        lightPositionVec4 = mat4_mul_vec4(light_rotation, lightPositionVec4);
        lightPosition = vec4_to_vec3(lightPositionVec4);
        setVec3(&shader, "lightPos", lightPosition);



        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, earth->index_count, GL_UNSIGNED_INT, 0);
        
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, moonTexture);
        useShader(&shader);
        
        model = mat4_identity();
        scale_xyz(&model, 0.1f, 0.1f, 0.1f);
        
        rotation_axis = vec3_create(0.5f, 1.0f, 0.0f);
        rotate_vec3(&model, (float)glfwGetTime() * radians(55.0f), &rotation_axis);

        projection = mat4_perspective(45.0f, 1920.0f/1080.0f, 0.1f, 100.0f); 
    
        modelLocation = glGetUniformLocation(shader.ID, "model");
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, model.m);
        viewLocation = glGetUniformLocation(shader.ID, "view");
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, view.m);
        projectionLocation = glGetUniformLocation(shader.ID, "projection");
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, projection.m);    
        glDrawElements(GL_TRIANGLES, moon->index_count, GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();   
    }
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;

}

void processInput(GLFWwindow* window){
    deltaTime = glfwGetTime() - previousTime;
    previousTime = glfwGetTime();
    float cameraspeed = deltaTime * 1.0f;
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPosition.z += cameraspeed;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPosition.z -= cameraspeed;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPosition.x -= cameraspeed;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPosition.x += cameraspeed;

}



