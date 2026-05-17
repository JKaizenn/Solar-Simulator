#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <glfw/glfw3.h>
#include "camera2D.h"

class UserInput
{
public:
    UserInput(Camera2D& camera);
    // Keyboard Input
    void processInput(GLFWwindow* window);

    // Mouse Input
    void mouseCallback(GLFWwindow* window, double xPos, double yPos);
    void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);

private:
    bool firstMouse {true};
    Camera2D& camera;

};
#endif