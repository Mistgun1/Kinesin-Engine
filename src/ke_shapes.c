#include "ke_shapes.h"
#include "ke_math.h"
#include <math.h>
#include <stdio.h>

void draw_triangle(shape *s, float angle, float side_length1, float side_length2, vec3 color){

    s->vertices[0].x = -1.0f;
    s->vertices[0].y = -1.0f;
    s->vertices[0].z = 0;
    s->vertices[0].r = color.x;
    s->vertices[0].g = color.y;
    s->vertices[0].b = color.z;
    s->vertices[0].u = -1.0f;
    s->vertices[0].v = -1.0f;

    s->vertices[1].x = side_length1;
    s->vertices[1].y = -1.0f;
    s->vertices[1].z = 0;
    s->vertices[1].r = color.x;
    s->vertices[1].g = color.y;
    s->vertices[1].b = color.z;
    s->vertices[1].u = side_length1;
    s->vertices[1].v = -1.0f;

    s->vertices[2].x = cosf(angle) * side_length2 ;
    s->vertices[2].y = sinf(angle) * side_length2;
    s->vertices[2].z = 0;
    s->vertices[2].r = color.x;
    s->vertices[2].g = color.y;
    s->vertices[2].b = color.z;
    s->vertices[2].u = cosf(angle) * side_length2;
    s->vertices[2].v = sinf(angle) * side_length2;

    s->indices[0] = 0;
    s->indices[1] = 1;
    s->indices[2] = 2;
    


}
