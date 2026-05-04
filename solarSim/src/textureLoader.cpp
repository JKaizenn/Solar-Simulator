// Image Processing - Turn images into textures
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#include "textureLoader.h"
#include "glad/glad.h"
#include <iostream>

Texture TextureLoader::load(const std::string& path)
{
        // Load texture
        Texture texture;
        texture.type = "planetTexture";

        // OPENGL Texture Logic
        glGenTextures(1, &texture.id);
        glBindTexture(GL_TEXTURE_2D, texture.id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);

        unsigned char* imgData = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

        if(imgData)
        {
            GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imgData);
            glGenerateMipmap(GL_TEXTURE_2D);
            std::cout << "Loaded: " << path << " | W:" << width << " H:" << height << " CH:" << nrChannels << '\n';
        }

        else
            std::cout << "Failed to load texture" << path << '\n';

        stbi_image_free(imgData);

        return texture;
}