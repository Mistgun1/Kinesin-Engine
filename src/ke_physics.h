#ifndef KE_PHYSICS_H
#define KE_PHYSICS_H

#include <math.h>
#include "ke_math.h"

#define GRAVITY_CONSTANT 6.6743 * pow(10, -11)

//force value
double gravitational_force(double mass1, double mass2, double distance);
vec3 acceleration(double mass,vec3 direction, double force);

#endif

