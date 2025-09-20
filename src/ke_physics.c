#include "ke_physics.h"


double gravitational_force(double mass1, double mass2, double distance){
    return (GRAVITY_CONSTANT * mass1 * mass2) / (distance * distance);
}

vec3 acceleration(double mass,vec3 direction, double force){
    vec3 acceleration;
    acceleration.x = direction.x * force / mass;
    acceleration.y = direction.y * force / mass;
    acceleration.z = direction.z * force / mass;
    return acceleration;
}

