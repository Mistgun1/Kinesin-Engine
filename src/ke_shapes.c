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
        // position    , color                    , texcoord    , normal
        -1.0f, -1.0f, 0, color.x, color.y, color.z,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f,
         1.0f, -1.0f, 0, color.x, color.y, color.z,  1.0f,  0.0f, 0.0f, 0.0f, 1.0f,
         0.5f,  1.0f, 0, color.x, color.y, color.z,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f
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

    int vertex_count = slices + 1  ;
    int index_count = (slices + 1)  * 3;

    shape* disc = generate_shape(vertex_count, index_count);

    disc->vertices[0] = 0;
    disc->vertices[1] = 0;
    disc->vertices[2] = 0;
    disc->vertices[3] = color.x;
    disc->vertices[4] = color.y;
    disc->vertices[5] = color.z;
    disc->vertices[6] = 0.5;
    disc->vertices[7] = 0.5;
    disc->vertices[8] = 0.0f;
    disc->vertices[9] = 0.0f;
    disc->vertices[10] = 1.0f;


    for (int i = 0; i < slices ; i++){
        disc->vertices[(i + 1) * 8 + 0] = cosf(i * 2  * PI / slices) ;
        disc->vertices[(i + 1) * 8 + 1] = sinf(i * 2  * PI / slices) ;
        disc->vertices[(i + 1) * 8 + 2] = 0;
        disc->vertices[(i + 1) * 8 + 3] = color.x;
        disc->vertices[(i + 1) * 8 + 4] = color.y;
        disc->vertices[(i + 1) * 8 + 5] = color.z;
        disc->vertices[(i + 1) * 8 + 6] = (cosf(i  * 2  * PI / slices) * 0.5) + 0.5;
        disc->vertices[(i + 1) * 8 + 7] = (sinf(i  * 2  * PI / slices) * 0.5) + 0.5;
        disc->vertices[(i + 1) * 8 + 8] = 0.0f;
        disc->vertices[(i + 1) * 8 + 9] = 0.0f;
        disc->vertices[(i + 1) * 8 + 10] = 1.0f;
    }

    for (int i = 0; i < slices + 1 ; i++){
        disc->indices[i * 3 + 0] = 0;
        disc->indices[i * 3 + 1] = i;
        disc->indices[i * 3 + 2] = i + 1;
    }
    disc->indices[slices * 3 + 0] = 0;
    disc->indices[slices * 3 + 1] = slices;
    disc->indices[slices * 3 + 2] = 1;

    return disc;
}



// TODO: fix this (texture coordinates and normals)
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

//slices should be even
shape* generate_sphere(vec3 color, int slices, int stacks){
    
    //tbh this is unreadable but it works
    //I lost my mind for 3 days trying to come up with this, even I don't understand it now
    //terry davis would be disappointed
    
    int vertex_count = slices * (stacks - 1) + 2;
    int index_count = slices * (stacks - 1) * 6   ;

    shape* sphere = generate_shape(vertex_count, index_count);

    sphere->vertices[0] = 0.0f;
    sphere->vertices[1] = 1.0f;
    sphere->vertices[2] = 0.0f;
    sphere->vertices[3] = color.x;
    sphere->vertices[4] = color.y;
    sphere->vertices[5] = color.z;
    sphere->vertices[6] = 0;
    sphere->vertices[7] = 0;
    sphere->vertices[8] = 0.0f;
    sphere->vertices[9] = 1.0f;
    sphere->vertices[10] = 0.0f;

    sphere->vertices[11] = 0.0f;
    sphere->vertices[12] = -1.0f;
    sphere->vertices[13] = 0.0f;
    sphere->vertices[14] = color.x;
    sphere->vertices[15] = color.y;
    sphere->vertices[16] = color.z;
    sphere->vertices[17] = 1.0;
    sphere->vertices[18] = 1.0;
    sphere->vertices[19] = 0.0f;
    sphere->vertices[20] = -1.0f;
    sphere->vertices[21] = 0.0f;

    for (int i = 1; i < stacks ; i++){
        float disc_radius = sqrtf((2.0f * i / stacks) * (2 - (2.0f * i / stacks)));
        float disc_level = 1 - ((float)i * 2 / stacks);
        for (int j = 0; j < slices ; j++){
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 0] = cosf(j * 2 * PI / slices) * disc_radius;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 1] = disc_level;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 2] = sinf(j * 2 * PI / slices) * disc_radius;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 3] = color.x;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 4] = color.y;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 5] = color.z;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 6] = cosf(j * PI / slices) * 0.5f + 0.5f ;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 7] = (float)i / stacks;
            vec3 normal = vec3_create(cosf(j * 2 * PI / slices), disc_level, sinf(j * 2 * PI / slices));
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 8] = normal.x;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 9] = normal.y;
            sphere->vertices[((i - 1) * slices + 2 + j) * 11 + 10] = normal.z;
        }
    }

    for (int i = 0; i < slices - 1 ; i++){
        sphere->indices[i * 3 + 0] = 0;
        sphere->indices[i * 3 + 1] = i + 2;
        sphere->indices[i * 3 + 2] = i + 3;

    }

    for (int i = 1; i < stacks - 1 ; i++){
        for (int j = 1; j <= slices + 1 ; j++){
            sphere->indices[(i * slices + j - 1) * 6 - (slices + 1) * 3 + 0] = (i - 1)* slices + j;
            sphere->indices[(i * slices + j - 1) * 6 - (slices + 1) * 3 + 1] = (i - 1)* slices + j + 1;
            sphere->indices[(i * slices + j - 1) * 6 - (slices + 1) * 3 + 2] = (i + 0)* slices + j;
            sphere->indices[(i * slices + j - 1) * 6 - (slices + 1) * 3 + 3] = (i - 1)* slices + j + 1;
            sphere->indices[(i * slices + j - 1) * 6 - (slices + 1) * 3 + 4] = (i + 0)* slices + j;
            sphere->indices[(i * slices + j - 1) * 6 - (slices + 1) * 3 + 5] = (i + 0)* slices + j + 1;
        }
    }           
                
    sphere->indices[(slices - 1)* 3 + 0] = 0;
    sphere->indices[(slices - 1)* 3 + 1] = slices + 1;
    sphere->indices[(slices - 1)* 3 + 2] = 2;
    
    sphere->indices[((stacks - 1) * slices + slices - 1) * 6 + 3] = (stacks - 2) * slices + slices;
    sphere->indices[((stacks - 1) * slices + slices - 1) * 6 + 4] = (stacks - 2) * slices + slices + 1;
    sphere->indices[((stacks - 1) * slices + slices - 1) * 6 + 5] = (stacks - 1) * slices + slices;

    int last_index = (stacks - 2) * slices * 6 + slices * 3;
    for (int i = 0; i < slices ; i++){
        int count = i + last_index;
        sphere->indices[last_index + i * 3 + 0] = 1;
        sphere->indices[last_index + i * 3 + 1] = (int)((last_index - slices * 3) / 6 + i + 2);
        sphere->indices[last_index + i * 3 + 2] = (int)((last_index - slices * 3) / 6 + i + 3);
    }

    sphere->indices[last_index + (slices - 1)* 3 + 0] = 1;
    sphere->indices[last_index + (slices - 1)* 3 + 1] = (last_index - slices * 3) / 6 + slices + 1;
    sphere->indices[last_index + (slices - 1)* 3 + 2] = (last_index - slices * 3) / 6 + 2;
   
    return sphere;
}

void free_shape(shape* shape){
    free(shape->vertices);
    free(shape->indices);
    free(shape);
}
