/*************************
 * Header File: PLANET
 * Author: Jessen
 * Summary:
 * The attributes of a planet 
 *************************/

#ifndef PLANET_H
#define PLANET_H

#include "physics/position.h"
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"
#include "shader.h"
#include "mesh.h"
#include <memory>

class Planet
{
public:
    // Constructors
    Planet(std::shared_ptr<Mesh> mesh, glm::vec2 position, float radius);

    // Destructor
    ~Planet();

    // Draw 
    void draw(Shader& shader);

private:
    // Shared mesh object
    std::shared_ptr<Mesh> mesh;

    // Geometry and Transform
    float radius;      // Size of planet
    Position position; // Where the planet/star sits in the scene
    
    // Orbital Motion
    float orbitRadius; // Distance from the sun
    float orbitSpeed;  // How fast the planet/star revolves
    float orbitAngle;  // Current angle in orbit

    // Self-Rotation
    float rotationAngle; // Current spin angle
    float rotationSpeed; // How fast the planet/star spins
};
#endif
