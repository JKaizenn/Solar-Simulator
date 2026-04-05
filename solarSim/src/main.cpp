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

// Shader
#include "shader.h"

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

    // Load shader
    Shader shader("solarSim/res/shaders/vertex.glsl", "solarSim/res/shaders/fragment.glsl");

    // Create a set of vertices for the sun object
    float sun[] = {
    // positions          // tex coords
    -0.33f,  0.33f, 0.0f,  0.0f, 1.0f,  // top-left
     0.33f,  0.33f, 0.0f,  1.0f, 1.0f,  // top-right
     0.33f, -0.33f, 0.0f,  1.0f, 0.0f,  // bottom-right
    -0.33f, -0.33f, 0.0f,  0.0f, 0.0f   // bottom-left
    };
    // Indices for sun object
    unsigned int sunIndices[] = {
        0, 1, 3,
        1, 2, 3
    };


    unsigned int VBO, VAO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sun), sun, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sunIndices), sunIndices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    // Textures

    // Generate Texture
    unsigned int sunTexture;

    // Sun Texture
    glGenTextures(1, &sunTexture);
    glBindTexture(GL_TEXTURE_2D, sunTexture);

    // Set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set the texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load image, create texture, generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("solarSim/res/shaders/textures/sun.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    else
        std::cout << "Failed to load Sun Texture!" << '\n';
    
    stbi_image_free(data);



    // Tell opengl which texture unit each texture belongs to
    shader.use();
    shader.setInt("sunTexture", 0);
    

    // Main Render Loop
    while (!glfwWindowShouldClose(window))
    {
        // Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, sunTexture);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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