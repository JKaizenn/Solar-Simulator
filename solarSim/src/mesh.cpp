#include "mesh.h"

/*********************************
 * CONSTRUCTOR
 *********************************/
Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures) : vertices(vertices), indices(indices), textures(textures) 
{
    setupMesh();
}

/*********************************
 * DESTRUCTOR
 *********************************/
Mesh::~Mesh()
{
    if(VAO)
        glDeleteVertexArrays(1, &VAO);
    if(VBO)
        glDeleteBuffers(1, &VBO);
    if(EBO)
        glDeleteBuffers(1, &EBO);
}

 /*********************************
 * SETUP MESH
 * Creates our VBO, VAO, and EBO 
 *********************************/
void Mesh::setupMesh()
{
    // Generate Arrays and Buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind Arrays and Buffers
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // Position Attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    // Normal Attributes
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position)); 

    // TexCoord Attributes
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position)); 

    glBindVertexArray(0);
}

 /*********************************
 * DRAW
 *********************************/
void Mesh::draw(Shader &shader)
{
    glActiveTexture(GL_TEXTURE0);
    if (!textures.empty())
        glBindTexture(GL_TEXTURE_2D, textures[0].id);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
