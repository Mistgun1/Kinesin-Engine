#ifndef KE_SHAPES_H
#define KE_SHAPES_H

#include "ke_math.h"

#define MAX_VERTICES 10000

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
    vertex vertices[MAX_VERTICES];
    int indices[MAX_VERTICES];
}shape;

// all shapes are drawn in a normalized space between -1 and 1
// 2D shapes are drawm on xy plane 
shape* generate_triangle(vec3 color);
shape* generate_square(vec3 color);
shape* generate_disc(vec3 color, int slices);
shape* generate_cube(vec3 color);


#endif
