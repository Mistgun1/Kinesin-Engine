#ifndef KE_RENDERER_H
#define KE_RENDERER_H

#include "se_gl.h"
#include "ke_shapes.h"
#include "ke_shader.h"
#include <stdarg.h>
void render_mesh(shape* mesh);

// lighting
void default_light(Shader *shader);
void default_material(Shader *shader);
void set_up_lighting(Shader *shader,vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, vec3 color);
void set_up_material(Shader *shader, vec3 ambient, vec3 diffuse, vec3 specular, float shininess);

#endif
