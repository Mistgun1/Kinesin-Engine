#include <stdio.h>
#include <GLFW/glfw3.h>
#include "se_gl.h"
#include "ke_window.h"
#include "ke_shader.h"
#include "ke_shapes.h"
#include "ke_math.h"
#include "ke_renderer.h"
#include "ke_camera.h"
#include "ke_transform.h"
#include "ke_texture.h"

void processInput(GLFWwindow* window);

vec3 cameraPosition;
vec3 cameraTarget;
vec3 cameraUp;

int main(int argc, char **argv){

    cameraPosition = vec3_create(0.0f, 0.0f, 0.0f);
    cameraTarget = vec3_create(0.0f, 0.0f, -1.0f);
    cameraUp = vec3_create(0.0f, 1.0f, 0.0f);

    glfwInit();
    GLFWwindow* window = createWindow(800, 600, "fps");
    
    se_init_opengl();

    Shader shader;
    shader.vertexFileName = "colorful.vs";
    shader.fragmentFileName = "colorful.fs";
    initShader(&shader);

    //unsigned int earth_texture = load_jpg_texture("earth.jpg", true);
    vec3 cubeColor = vec3_create(1.0f, 0.0f, 0.0f);
    shape* cube = generate_cube(cubeColor);
    shape* floor = generate_square(vec3_create(0.5f, 0.5f, 0.5f));

    render_mesh(cube);
    render_mesh(floor);

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)){

        processInput(window);

        glClearColor(0.7f, 0.8f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //glBindTexture(GL_TEXTURE_2D, earth_texture);
        useShader(&shader);
        mat4 model = mat4_identity();
        mat4 view = mat4_look_at(cameraPosition, cameraTarget, cameraUp);
        mat4 projection = mat4_perspective(45.0f, 800.0f/600.0f, 0.1f, 100.0f);
       
        translate_xyz(&model, 0.0f, 0.0f, 10.0f);
        //scale_xyz(&model, 0.0f, 4.0f, 0.0f);

        model = mat4_transpose(model);
        view = mat4_transpose(view);
        projection = mat4_transpose(projection);

        setMat4(&shader, "model", model);
        setMat4(&shader, "view", view);
        setMat4(&shader, "projection", projection);


        setVec3(&shader, "viewPos", cameraPosition);
        default_light(&shader);

        setInt(&shader, "material.diffuse", 0);
        
        glBindVertexArray(cube->VAO);
        glDrawElements(GL_TRIANGLES, cube->index_count, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glDeleteVertexArrays(1, &cube->VAO);
    glDeleteBuffers(1, &cube->VBO);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}
