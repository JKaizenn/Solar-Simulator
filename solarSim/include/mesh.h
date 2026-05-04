/*********************************
 * Header File: MESH
 * Author: Jessen 
 * Summary:
 * Everything we need to know about:
 * Vertex Buffer Objects
 * Vertex Array Objects
 * Element Buffer Objects
 * Vertices, Matrices, and other geometric data
 *********************************/
#ifndef MESH_H
#define MESH_H

#include "vertex.h"
#include "texture.h"
#include "shader.h"
#include "glad/glad.h"
#include <glm/glm.hpp>

class Mesh
{
public:
    // Constructors
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indicies, std::vector<Texture> textures);

    // Destructor
    ~Mesh();

    // Draw
    void draw(Shader &shader);

    // Member Variables
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

private:
    // Rendering
    GLuint VAO, VBO, EBO;  // Mesh Buffers
    void setupMesh(); 
};
#endif