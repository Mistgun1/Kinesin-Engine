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
void draw_triangle(shape *s, float angle, float side_length1, float side_length2, vec3 color);
void draw_isosceles_triangle(shape *s, float angle, float side_length);
void draw_square(shape *s);
void draw_circle(shape *s);
void draw_cube(shape *s);
void draw_rectangle(shape *s, float height, float width, float depth);
void draw_sphere(shape *s, int slices, int stacks);

#endif
