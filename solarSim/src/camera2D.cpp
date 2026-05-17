#include "camera2D.h"

/*********************************
 * DEFAULT CONSTRUCTOR
 *********************************/
Camera2D::Camera2D(glm::vec2 cameraPosition, glm::vec2 cameraOrigin) :
cameraPosition(cameraPosition), cameraOrigin(cameraOrigin){ }

/*********************************
 * GET PROJECTION MATRIX
 *********************************/
glm::mat4 Camera2D::getProjectionMatrix(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT)
{
    glm::mat4 projection = glm::ortho(0.0f, float(SCR_WIDTH), 0.0f, (float) SCR_HEIGHT);
    return projection;
}

/*********************************
 * GET VIEW MATRIX
 *********************************/
glm::mat4 Camera2D::getViewMatrix()
{
    // Translation
    glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(cameraPosition, 0.0f));

    // Scale
    glm::mat4 scale = glm::scale(translate, glm::vec3(zoom, zoom, 1.0f));

    return scale;

}

/*********************************
 * PAN
 * Allows the user to move the camera left and right
 *********************************/
void Camera2D::pan(glm::vec2 delta)
{
    cameraPosition += delta;
}

 /*********************************
 * ZOOM
 * Allows the user to use the scroll wheel to zoom in and out
 *********************************/
void Camera2D::setZoom(float zoom)
{
    this->zoom += zoom;
}

