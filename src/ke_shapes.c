#include "ke_shapes.h"
#include "ke_math.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

shape* generate_triangle(vec3 color){

    shape* triangle;
    
    triangle->vertices[0].x = -1.0f;
    triangle->vertices[0].y = -1.0f;
    triangle->vertices[0].z = 0;
    triangle->vertices[0].r = color.x;
    triangle->vertices[0].g = color.y;
    triangle->vertices[0].b = color.z;
    triangle->vertices[0].u = -1.0f;
    triangle->vertices[0].v = -1.0f;

    triangle->vertices[1].x = 1.0f;
    triangle->vertices[1].y = -1.0f;
    triangle->vertices[1].z = 0;
    triangle->vertices[1].r = color.x;
    triangle->vertices[1].g = color.y;
    triangle->vertices[1].b = color.z;
    triangle->vertices[1].u = 1.0f;
    triangle->vertices[1].v = -1.0f;

    triangle->vertices[2].x = 0.5f;
    triangle->vertices[2].y = 1.0f;
    triangle->vertices[2].z = 0;
    triangle->vertices[2].r = color.x;
    triangle->vertices[2].g = color.y;
    triangle->vertices[2].b = color.z;
    triangle->vertices[2].u = 0.5f;
    triangle->vertices[2].v = 1.0f;

    triangle->indices[0] = 0;
    triangle->indices[1] = 1;
    triangle->indices[2] = 2;
    
    return triangle;
}

shape* generate_square(vec3 color){

    shape* square;
    
    square->vertices[0].x = -1.0f;
    square->vertices[0].y = -1.0f;
    square->vertices[0].z = 0;
    square->vertices[0].r = color.x;
    square->vertices[0].g = color.y;
    square->vertices[0].b = color.z;
    square->vertices[0].u = -1.0f;
    square->vertices[0].v = -1.0f;

    square->vertices[1].x = 1.0f;
    square->vertices[1].y = -1.0f;
    square->vertices[1].z = 0;
    square->vertices[1].r = color.x;
    square->vertices[1].g = color.y;
    square->vertices[1].b = color.z;
    square->vertices[1].u = 1.0f;
    square->vertices[1].v = -1.0f;

    square->vertices[2].x = 1.0f;
    square->vertices[2].y = 1.0f;
    square->vertices[2].z = 0;
    square->vertices[2].r = color.x;
    square->vertices[2].g = color.y;
    square->vertices[2].b = color.z;
    square->vertices[2].u = 1.0f;
    square->vertices[2].v = 1.0f;

    square->vertices[3].x = -1.0f;
    square->vertices[3].y = 1.0f;
    square->vertices[3].z = 0;
    square->vertices[3].r = color.x;
    square->vertices[3].g = color.y;
    square->vertices[3].b = color.z;
    square->vertices[3].u = -1.0f;
    square->vertices[3].v = 1.0f;

    square->indices[0] = 0;
    square->indices[1] = 1;
    square->indices[2] = 3;
    square->indices[3] = 1;
    square->indices[4] = 2;
    square->indices[5] = 3;
    
    return square;
}


shape* generate_disk(vec3 color, int slices){

    shape* disk;
    
    for (int i = 0; i < slices; i++){
        disk->vertices[i].x = cosf(i * 2  * PI / slices);
        disk->vertices[i].y = sinf(i * 2  * PI / slices);
        disk->vertices[i].z = 0;
        disk->vertices[i].r = color.x;
        disk->vertices[i].g = color.y;
        disk->vertices[i].b = color.z;
        disk->vertices[i].u = cosf(i * 2  * PI / slices);
        disk->vertices[i].v = sinf(i * 2  * PI / slices);
    }

    for (int i = 0; i < slices; i++){
        disk->indices[i * 3 + 0] = 0;
        disk->indices[i * 3 + 1] = i + 1;
        disk->indices[i * 3 + 2] = i + 2;
    }

    return disk;
}

shape* generate_cube(vec3 color){

    shape* cube;
    
    cube = generate_square(color);
    memcpy(cube->vertices + 4, cube->vertices, sizeof(vertex) * 4);
    for (int i = 0; i < 4; i++){
        cube->vertices[i].z = -1.0f;
    }
    for (int i = 4; i < 8; i++){
        cube->vertices[i].z = 1.0f;
    }

    int indices[] = {
        0, 1 , 3,  1, 2 , 3,
        4, 5 , 7,  5, 6 , 7,
        0, 4 , 1,  1, 5 , 4,
        2, 6 , 3,  3, 7 , 6,
        0, 2 , 4,  4, 6 , 2,
        1, 3 , 5,  5, 7 , 3,
    };

    for (int i = 0; i < 36; i++){
        cube->indices[i] = indices[i];
    }

    return cube;
        
}
