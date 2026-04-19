#include "planetFactory.h"

std::vector<std::shared_ptr<Planet>> PlanetFactory::createAll(const std::string& path)
{
    // Load data from JSON
    std::ifstream file(path);
    nlohmann::json data = nlohmann::json::parse(file);
    std::vector<std::shared_ptr<Planet>> planets;

    if(!file.is_open())
    {
        std::cout << "Failed to open: " << path << '\n';
        return planets;
    }
    std::cout << "Opened: " << path << '\n';

    std::cout << "Loaded: " << planets.size() << " planets" << '\n';
    for (auto& p : planets)
        std::cout << "Planets Created: " << '\n';

    for (auto& p : data)
    {
        float radius        = p["radius"];
        float orbitRadius   = p["orbitRadius"];
        float orbitSpeed    = p["orbitSpeed"];
        float rotationSpeed = p["rotationSpeed"];
        std::string texPath = p["texture"];

        Texture texture = TextureLoader::load(texPath);

        std::shared_ptr<Mesh> mesh = MeshGenerator::generateCircle(radius);

        planets.push_back(std::make_shared<Planet>(
            mesh,
            glm::vec2(0.0f, 0.0f),
            radius,
            orbitRadius,
            orbitSpeed,
            rotationSpeed
        ));
    }
    return planets;
}