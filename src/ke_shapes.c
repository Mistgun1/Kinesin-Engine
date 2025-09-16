#include "ke_shapes.h"
#include "ke_math.h"
#include <math.h>
#include <stdio.h>
#include <string.h>


shape* generate_shape(int vertex_count, int index_count){
    shape* result_shape;
    result_shape = malloc(sizeof(shape));
    result_shape->vertex_count = vertex_count;
    result_shape->index_count = index_count;
    result_shape->vertices = malloc(sizeof(float) * vertex_count * 8);
    result_shape->indices = malloc(sizeof(int) * index_count);
    return result_shape;
}


shape* generate_triangle(vec3 color){
   
    int vertex_count = 3;
    int index_count = 3;

    float triangle_vertices[] = {
        -1.0f, -1.0f, 0, color.x, color.y, color.z,  0.0f,  0.0f,
         1.0f, -1.0f, 0, color.x, color.y, color.z,  1.0f,  0.0f,
         0.5f,  1.0f, 0, color.x, color.y, color.z,  0.5f,  1.0f
    };
   
    int triangle_indices[] = {
        0, 1, 2
    };

    shape* triangle = generate_shape(vertex_count, index_count);

    for (int i = 0; i < triangle->vertex_count * 8; i++){
        triangle->vertices[i] = triangle_vertices[i];
    }
   
    for (int i = 0; i < index_count; i++){
        triangle->indices[i] = triangle_indices[i];
    }

    return triangle;
}

shape* generate_square(vec3 color){

    int vertex_count = 4;
    int index_count = 6;

    float square_vertices[] = {
        -1.0f, -1.0f, 0, color.x, color.y, color.z,  0.0f,  0.0f,
         1.0f, -1.0f, 0, color.x, color.y, color.z,  1.0f,  0.0f,
         1.0f,  1.0f, 0, color.x, color.y, color.z,  1.0f,  1.0f,
        -1.0f,  1.0f, 0, color.x, color.y, color.z,  0.0f,  1.0f
    };
   
    int square_indices[] = {
        0, 1, 3, 1, 2, 3
    };


    shape* square = generate_shape(vertex_count, index_count);

    for (int i = 0; i < vertex_count * 8; i++){
        square->vertices[i] = square_vertices[i];
    }
   
    for (int i = 0; i < index_count; i++){
        square->indices[i] = square_indices[i];
    }

    return square;
}



shape* generate_disc(vec3 color, int slices){

    int vertex_count = slices ;
    int index_count = slices  * 3;

    shape* disc = generate_shape(vertex_count, index_count);

    disc->vertices[0] = 0;
    disc->vertices[1] = 0;
    disc->vertices[2] = 0;
    disc->vertices[3] = color.x;
    disc->vertices[4] = color.y;
    disc->vertices[5] = color.z;
    disc->vertices[6] = 0.5;
    disc->vertices[7] = 0.5;

    for (int i = 8; i < slices * 8; i+=8){
        disc->vertices[i + 0] = cosf((i - 1)  * 2  * PI / slices);
        disc->vertices[i + 1] = sinf((i - 1) * 2  * PI / slices);
        disc->vertices[i + 2] = 0;
        disc->vertices[i + 3] = color.x;
        disc->vertices[i + 4] = color.y;
        disc->vertices[i + 5] = color.z;
        disc->vertices[i + 6] = (cosf((i - 1)* 2  * PI / slices) * 0.5) + 0.5;
        disc->vertices[i + 7] = (sinf((i - 1) * 2  * PI / slices) * 0.5) + 0.5;
    }

    for (int i = 0; i < slices ; i++){
        disc->indices[i * 3 + 0] = 0;
        disc->indices[i * 3 + 1] = i + 1;
        disc->indices[i * 3 + 2] = i + 2;
    }


    return disc;
}

shape* generate_cube(vec3 color){

    int vertex_count = 8;
    int index_count = 36;

    float cube_vertices[] = {
        -1.0f, -1.0f, -1.0f, color.x, color.y, color.z,  0.0f,  0.0f,
         1.0f, -1.0f, -1.0f, color.x, color.y, color.z,  1.0f,  0.0f,
         1.0f,  1.0f, -1.0f, color.x, color.y, color.z,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f, color.x, color.y, color.z,  0.0f,  1.0f,
        -1.0f, -1.0f,  1.0f, color.x, color.y, color.z,  0.0f,  0.0f,
         1.0f, -1.0f,  1.0f, color.x, color.y, color.z,  1.0f,  0.0f,
         1.0f,  1.0f,  1.0f, color.x, color.y, color.z,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f, color.x, color.y, color.z,  0.0f,  1.0f
    };

    int cube_indices[] = {
        0, 1 , 3,  1, 2 , 3,
        1, 5 , 2,  5, 6 , 2,
        5, 4 , 6,  4, 7 , 6,
        4, 7 , 3,  4, 0 , 3,
        3, 7 , 6,  6, 3 , 2,
        1, 0 , 5,  4, 0 , 5
    };

    shape* cube = generate_shape(vertex_count, index_count);

    for (int i = 0; i < vertex_count * 8; i++){
        cube->vertices[i] = cube_vertices[i];
    }
   
    for (int i = 0; i < index_count; i++){
        cube->indices[i] = cube_indices[i];
    }

    return cube;
}


shape* generate_sphere(vec3 color, int slices, int stacks){

    int vertex_count = slices * stacks;
    int index_count = slices * stacks * 6;

    shape* sphere = generate_shape(vertex_count, index_count);

    sphere->vertices[0] = 0.0f;
    sphere->vertices[1] = 1.0f;
    sphere->vertices[2] = 0.0f;
    sphere->vertices[3] = color.x;
    sphere->vertices[4] = color.y;
    sphere->vertices[5] = color.z;
    sphere->vertices[6] = 1.0f;
    sphere->vertices[7] = 1.0f;

    sphere->vertices[8] = 0.0f;
    sphere->vertices[9] = -1.0f;
    sphere->vertices[10] = 0.0f;
    sphere->vertices[11] = color.x;
    sphere->vertices[12] = color.y;
    sphere->vertices[13] = color.z;
    sphere->vertices[14] = 0;
    sphere->vertices[15] = 0;

    for (int i = 0; i < stacks ; i++){
        for (int j = 0; j < slices; j++){
            sphere->vertices[i * slices * 8 + j * 8 + 0] = cosf(j * 2 * PI / slices);
            sphere->vertices[i * slices * 8 + j * 8 + 1] = (float)stacks / i;
            sphere->vertices[i * slices * 8 + j * 8 + 2] = sinf(j * 2 * PI / slices);
            sphere->vertices[i * slices * 8 + j * 8 + 3] = color.x;
            sphere->vertices[i * slices * 8 + j * 8 + 4] = color.y;
            sphere->vertices[i * slices * 8 + j * 8 + 5] = color.z;
            sphere->vertices[i * slices * 8 + j * 8 + 6] = cosf(j * 2 * PI / slices);
            sphere->vertices[i * slices * 8 + j * 8 + 7] = (float)stacks / i;
        }
    }

    for (int i = 0; i < stacks ; i++){
        for (int j = 0; j < slices; j++){

        }
    }

    return sphere;
}

void free_shape(shape* shape){
    free(shape->vertices);
    free(shape->indices);
    free(shape);
}
