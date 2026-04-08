#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp> // For math


#ifndef CANVAS_H
#define CANVAS_H

class Canvas
{
public:
    Canvas();
    ~Canvas();


    // Utility Drawing Methods
    void drawCircle();

    void drawOval();

    void drawSquare();

    void drawTriangle();

    
private:



};
#endif