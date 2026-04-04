/*********************************
 * MESH
 * Everything we need to know about:
 * Vertex Buffer Objects
 * Vertex Array Objects
 * Element Buffer Objects
 * Vertices, Matrices, and other geometric data
 *********************************/
#include <glm/glm.hpp>

#ifndef MESH_H
#define MESH_H

class Mesh
{
public:
    // Constructors
    

    // Destructor
    ~Mesh();

    // VBO


    // VAO 


    // EBO



private:
    unsigned int VBO, VAO, EBO;
    float vertices        {};
    unsigned int indicies {};
    glm::vec3 cubePositions   {};

};
#endif