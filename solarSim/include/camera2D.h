/*************************
 * Header File: CAMERA 2D
 * Author: Jessen
 * Summary:
 * Everything we need to know about a 2D Camera in Space (Literally)
 *************************/
#define CAMERA_2D_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

class Camera2D
{
public:
    // Constructors
    Camera2D(glm::vec2 FocusPosition, float zoom) : FocusPosition(FocusPosition), zoom(zoom) {}

    // Getters

    // Setters

    // Projection Matrix
    glm::mat4x4 getProjectionMatrix();


private:
    glm::vec2 FocusPosition;
    float zoom;


};
#endif