#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <glfw/glfw3.h>



class UserInput
{
public:

    // Keyboard Input
    void processInput(GLFWwindow* window);

    // Mouse Input
    void mouseCallback(GLFWwindow* window, double xPos, double yPos);
    void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);


private:
    bool firstMouse {true};

};
#endif