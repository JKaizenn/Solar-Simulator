/*********************************
 * Header File: Planet Factory
 * Author: Jessen
 * Summary:
 * Creates planet objects from JSON files
 *********************************/
#ifndef PLANET_FACTORY
#define PLANET_FACTORY

#include "planet.h"
#include "meshGenerator.h"
#include "texture.h"
#include "textureLoader.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <glad/glad.h>


class PlanetFactory
{
public:
    // Create planet with json file data
    static std::vector<std::shared_ptr<Planet>> createAll(const std::string& path);


private:


};
#endif