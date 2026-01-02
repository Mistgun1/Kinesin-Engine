#include "ke_renderer.h"


void render_mesh(shape* mesh){

    glGenVertexArrays(1, &mesh->VAO);
    glBindVertexArray(mesh->VAO);

    glGenBuffers(1, &mesh->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh->vertex_count * 11, mesh->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &mesh->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * mesh->index_count, mesh->indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8 * sizeof(float)));
    glEnableVertexAttribArray(3);
}

//lighting
void default_light(Shader *shader){
    setVec3(shader, "light.position", vec3_create(0.0f, 10.0f, -1.0f));
    setVec3(shader, "light.ambient", vec3_create(1.f, 1.f, 1.f));
    setVec3(shader, "light.diffuse", vec3_create(0.9f, 0.9f, 0.9f));
    setVec3(shader, "light.specular", vec3_create(1.0f, 1.0f, 1.0f));
    setVec3(shader, "light.color", vec3_create(1.0f, 1.0f, 1.0f));
}
void default_material(Shader *shader){
    setVec3(shader, "material.ambient", vec3_create(0.2f, 0.2f, 0.2f));
    setVec3(shader, "material.diffuse", vec3_create(0.9f, 0.9f, 0.9f));
    setVec3(shader, "material.specular", vec3_create(1.0f, 1.0f, 1.0f));
    setFloat(shader, "material.shininess", 0.0f);
}

void set_up_lighting(Shader *shader,vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, vec3 color){
    setVec3(shader, "light.position", position);
    setVec3(shader, "light.ambient", ambient);
    setVec3(shader, "light.diffuse", diffuse);
    setVec3(shader, "light.specular", specular);
    setVec3(shader, "light.color", color);
}

void set_up_material(Shader *shader, vec3 ambient, vec3 diffuse, vec3 specular, float shininess){
    setVec3(shader, "material.ambient", ambient);
    setVec3(shader, "material.diffuse", diffuse);
    setVec3(shader, "material.specular", specular);
    setFloat(shader, "material.shininess", shininess);
}

