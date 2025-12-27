#ifndef KE_SHAPES_H
#define KE_SHAPES_H

#include "ke_math.h"

#define MAX_VERTICES 10000
#define MAX_INDICES 10000

typedef struct vertex{
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float u;
    float v;
}vertex;

typedef struct shape{
    float* vertices;
    int* indices;
    int vertex_count;
    int index_count;
    unsigned int VBO; 
    unsigned int VAO;
    unsigned int EBO;
}shape;

// all shapes are drawn in a normalized space between -1 and 1
// 2D shapes are drawm on xy plane

shape* generate_shape(int vertex_count, int index_count);

shape* generate_triangle(vec3 color);
shape* generate_square(vec3 color);
shape* generate_disc(vec3 color, int slices);
shape* generate_cube(vec3 color);
shape* generate_sphere(vec3 color, int slices, int stacks);

void free_shape(shape* shape);

#endif
