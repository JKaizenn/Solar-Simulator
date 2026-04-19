#include "planet.h"
#include "glm/gtc/matrix_transform.hpp"
#include <cmath>

Planet::Planet(std::shared_ptr<Mesh> mesh, glm::vec2 position, float radius,
       float orbitRadius, float orbitSpeed, float rotationSpeed ) :
       mesh(mesh),
       position(position.x, position.y),
       radius(radius),
       orbitRadius(orbitRadius),
       orbitSpeed(orbitSpeed),
       rotationSpeed(rotationSpeed)
{ }

Planet::~Planet() { }

void Planet::draw(Shader& shader)
{
    shader.use();
    orbitAngle = (float)glfwGetTime() * orbitSpeed;

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(
        orbitRadius * cos(orbitAngle),
        orbitRadius * sin(orbitAngle),
        0.0f
    ));

    shader.setMat4("transform", trans);
    mesh->draw(shader);
}
