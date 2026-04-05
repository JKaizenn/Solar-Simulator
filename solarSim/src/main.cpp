// Core Libraries for Windowing/Rendering
#include <glad.h>
#include <glfw/glfw3.h>

// GLM - OpenGL Math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Image Processing - Turn images into textures
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

// ImGui - UI
#include "imgui/imgui.h"

// Camera
#include "camera.h"

// Debugging and Console Output
#include <iostream>

// GLOBALS
// Screen Dimensions
const unsigned int SCR_WIDTH  {800};
const unsigned int SCR_HEIGHT {600};


/*********************************
 * MAIN
 *********************************/
int main()
{
    // Initialize GLFW and Handle Errors
    if (!glfwInit())
    {
        std::cout << "GLFW Failed to Initialize!" << '\n';
        glfwTerminate();
        return -1;
    }

    // Initialize GLFW Window Hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // GLFW Window Hint for Apple Devices
    #ifndef __APPLE__
        glfwWindowHint(GLFW_OPEN_GL_FORWARD_COMPAT, GL_TRUE);
    #endif


    // Create a window variable
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Solar Simulator", NULL, NULL);

    // Handle errors if window doesn't open properly
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW Window!" << '\n';
        glfwTerminate();
        return -1;
    }

    // Configure Window Contexts
    glfwMakeContextCurrent(window);


    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD!" << '\n';
        return -1;
    }


    //--------------------------------------------------------

    // Create a set of vertices for the sun object
    float sun[] = {
        // positions
        -0.33f,   0.33f, 0.0f,  // top-left
         0.33f,   0.33f, 0.0f,  // top-right
         0.33f,  -0.33f, 0.0f,  // bottom-right
        -0.33f,  -0.33f, 0.0f   // bottom-left
    };
    // Indices for sun object
    unsigned int sunIndices[] = {
        0, 1, 3,
        1, 2, 3
    };



    // Textures
    



















    // Main Render Loop
    while (!glfwWindowShouldClose(window))
    {
        // Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();
    return 0;
}

/*********************************
 * FRAMEBUFFER SIZE CALLBACK
 * glfw: whenever the window size changed (by OS or user resize) this callback function executes
 *********************************/
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}