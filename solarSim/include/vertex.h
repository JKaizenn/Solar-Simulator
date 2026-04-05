/*********************************
 * VERTEX
 * Everything we need to know about:
 * Vertex Objects
 *********************************/
#include <glm/glm.hpp>

#ifndef VERTEX_H
#define VERTEX_H

struct Vertex
{
    glm::vec3 Position  {}; // 3 floats for X, Y, Z
    glm::vec3 Normal    {}; // 3 floats for normal vector
    glm::vec2 TexCoords {}; // 2 floats for texture coordinates
};
#endif