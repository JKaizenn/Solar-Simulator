/*********************************
 * Header File: Mesh Generator
 * Author: Jessen
 * Summary:
 * Procedural mesh generation utilities
 *********************************/
#ifndef MESH_GENERATOR_H
#define MESH_GENERATOR_H

#include "mesh.h"
#include <vector>
#include <memory>
#include <cmath>


class MeshGenerator
{
public:
    // Generate Mesh
    static std::shared_ptr<Mesh> generateCircle(float radius, int segments = 36);




private:


};



#endif