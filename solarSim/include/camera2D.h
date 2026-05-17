/*************************
 * Header File: CAMERA 2D
 * Author: Jessen
 * Summary:
 * Everything we need to know about a 2D Camera in Space (Literally)
 *************************/
#ifndef CAMERA_2D_H
#define CAMERA_2D_H

#include "userInput.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <vector>

enum Camera_Movement
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Camera2D
{
public:
    Camera2D(glm::vec2 cameraPosition, glm::vec2 cameraOrigin) : cameraPosition(cameraPosition), cameraOrigin(cameraOrigin) { }

    // Setup Orthographic Projection
    glm::mat4 getProjectionMatrix(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT);

    // Setup View Matrix
    glm::mat4 getViewMatrix();

    // Pan the Camera
    void pan(glm::vec2 delta);

    // SetZoom
    void setZoom(float zoom);

private:
    // Camera State
    glm::vec2 cameraPosition = glm::vec2(0.0f, 0.0f);
    glm::vec2 cameraOrigin   = glm::vec2(0.0f, 0.0f);

    // Camera Speed
    glm::vec2 delta = glm::vec2(0.0f, 0.0f);

    // Camera Scale (Zoom)
    float zoom { 0.0f };

};
#endif