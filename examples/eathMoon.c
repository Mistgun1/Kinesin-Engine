#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "ke_math.h"
#include "ke_window.h"
#include "se_gl.h"
#include "ke_camera.h"
#include "ke_shader.h"
#include "ke_shapes.h"
#include "ke_transform.h"
#include "ke_texture.h"


void processInput(GLFWwindow* window);

float deltaTime = 0.0f;
float previousTime = 0.0f;

vec3 cameraPosition;
vec3 cameraTarget;
vec3 cameraUp;

int main(int argc, char *argv[]){
   
    cameraPosition = vec3_create(0.0f, 0.0f, -10.0f);
    cameraTarget = vec3_create(0.0f, 0.0f, 0.0f);
    cameraUp = vec3_create(0.0f, 1.0f, 0.0f);
    
    glfwInit();
    GLFWwindow* window = createWindow(1920, 1080, "eath moon");
    
    se_init_opengl();

    Shader shader;
    shader.vertexFileName = "colorful.vs";
    shader.fragmentFileName = "colorful.fs";
    initShader(&shader);
    
    unsigned int earthTexture = load_jpg_texture("earth.jpg", false);
    unsigned int moonTexture = load_jpg_texture("moon.jpg", true);
    
    vec3 white = vec3_create(1.0f, 1.0f, 1.0f);
    shape* earth = generate_sphere(white , 200, 200);
    shape* moon = generate_sphere(white , 200, 200);

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * earth->vertex_count *11, earth->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * earth->index_count, earth->indices, GL_STATIC_DRAW);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * moon->vertex_count *11, moon->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * moon->index_count, moon->indices, GL_STATIC_DRAW);

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

        glBindTexture(GL_TEXTURE_2D, earthTexture);
        useShader(&shader);
        
        mat4 model = mat4_identity();
        scale_xyz(&model, 0.1f, 0.1f, 0.1f);

        mat4 view = mat4_look_at(cameraPosition, cameraTarget, cameraUp);
   
        mat4 projection = mat4_perspective(45.0f, 1920.0f/1080.0f, 0.1f, 100.0f);
        //mat4 projection = mat4_orthographic(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);
    
        setMat4(&shader, "model", model);
        setMat4(&shader, "view", view);
        setMat4(&shader, "projection", projection);

        vec3 lightPosition = vec3_create(20.0f, 0.0f, 12.0f);
        vec3 rotation_axis = vec3_create(0.0f, 1.0f, 0.0f);
        mat4 light_rotation = mat4_rotate((float)glfwGetTime() * radians(55.0f), &rotation_axis);
        vec4 lightPositionVec4 = vec3_to_vec4(lightPosition);
        lightPositionVec4 = mat4_mul_vec4(light_rotation, lightPositionVec4);
        lightPosition = vec4_to_vec3(lightPositionVec4);
        setVec3(&shader, "lightPos", lightPosition);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, earth->index_count, GL_UNSIGNED_INT, 0);
        
        glBindTexture(GL_TEXTURE_2D, moonTexture);
        glBindVertexArray(0);

        mat4 moon_model = mat4_identity();
        scale_xyz(&moon_model , 0.05f, 0.05f, 0.05f);
        translate_xyz(&moon_model, 0.0f, 0.0f, 0.0f);
        rotate_xyz(&moon_model , (float)glfwGetTime() * radians(40.0f), 0.0f, 1.0f, 0.0f);

        setMat4(&shader, "model", moon_model);

        glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES, moon->index_count, GL_UNSIGNED_INT, 0);

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
    float cameraspeed = deltaTime * 2.5f;
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        cameraPosition.z += cameraspeed;
        cameraTarget.z += cameraspeed;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        cameraPosition.z -= cameraspeed;
        cameraTarget.z -= cameraspeed;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        cameraPosition.x -= cameraspeed;
        cameraTarget.x -= cameraspeed;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        cameraPosition.x += cameraspeed;
        cameraTarget.x += cameraspeed;
    }
}



