#include "camera2D.h"

// Constructor
Camera2D::Camera2D(glm::vec2 cameraPosition, glm::vec2 cameraOrigin) :
cameraPosition(cameraPosition), cameraOrigin(cameraOrigin){ }

// Getters
glm::mat4 Camera2D::getProjectionMatrix()
{
    return glm::mat4(1.0f);
}
