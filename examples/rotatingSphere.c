#include <stdio.h>
#include "se_gl.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <unistd.h>
#include "ke_shader.h"
#include "ke_math.h"
#include "stb_image.h"
#include "ke_camera.h"
#include "ke_transform.h"
#include "ke_window.h"
#include "ke_shapes.h"


void processInput(GLFWwindow *window);

int main(void){
    
    glfwInit();
    GLFWwindow* window = createWindow(1920, 1080, "rotating sphere");
    se_init_opengl();

    Shader colorful;
    colorful.vertexFileName = "colorful.vs";
    colorful.fragmentFileName = "colorful.fs";
    initShader(&colorful);

    vec3 white = vec3_create(1.0f, 1.0f, 1.0f);
    shape* sphere = generate_sphere(white , 60, 60);


    unsigned int texture;
    glGenTextures(1, &texture); 
    glBindTexture(GL_TEXTURE_2D, texture);
    // load and generate the texture
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load("../resources/textures/okinawa.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture\n");
    }
    stbi_image_free(data); 

    //VAO and VBO
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sphere->vertex_count *8, sphere->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * sphere->index_count, sphere->indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
   
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    //glBindVertexArray(0);




    glEnable(GL_DEPTH_TEST);  

    while(!glfwWindowShouldClose(window)){
        processInput(window);
        glClearColor(0.6f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        useShader(&colorful);
        
        mat4 model = mat4_identity();
        scale_xyz(&model, 0.1f, 0.1f, 0.1f);
       
        vec3 rotation_axis = vec3_create(0.5f, 1.0f, 0.0f);
        rotate_vec3(&model, (float)glfwGetTime() * radians(55.0f), &rotation_axis);

        mat4 view = mat4_identity();
        translate_xyz(&view, 0.0f, 0.0f, -3.0f);
    
        mat4 projection = mat4_perspective(45.0f, 1920.0f/1080.0f, 0.1f, 100.0f); 
    
        int modelLocation = glGetUniformLocation(colorful.ID, "model");
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, model.m);
        int viewLocation = glGetUniformLocation(colorful.ID, "view");
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, view.m);
        int projectionLocation = glGetUniformLocation(colorful.ID, "projection");
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, projection.m);
        
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        glDrawElements(GL_TRIANGLES, sphere->index_count, GL_UNSIGNED_INT, 0);
        
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

