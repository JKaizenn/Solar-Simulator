#include "meshGenerator.h"


/*********************************
 * GENERATE CIRCLE
 * Used a perimeter with a radius and segments to create a circle of vertices
 *********************************/
std::shared_ptr<Mesh> MeshGenerator::generateCircle(float radius, int segments)
{
    // Create a set of vertices to store position, normal, and texture coordinates
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    // Center Vertex
    Vertex center;
    center.Position  = { 0.0f, 0.0f, 0.0f };
    center.Normal    = { 0.0f, 0.0f, 1.0f };
    center.TexCoords = { 0.5f, 0.5f };
    vertices.push_back(center);

    // Perimeter vertices
    for (int i {}; i <= segments; i++)
    {
        float angle = (2.0f * M_PI * i) / segments;
        Vertex v;
        v.Position  = { radius * cos(angle), radius * sin (angle), 0.0f };
        v.Normal    = { 0.0f, 0.0f, 0.0f };
        v.TexCoords = { (cos(angle) + 1.0f) / 2.0f, sin(angle + 1.0f) / 2.0f};
        vertices.push_back(v); 
    }

    // Indices
    for (int i {1}; i <= segments; i++)
    {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }

    return std::make_shared<Mesh>(vertices, indices, std::vector<Texture>{});

}