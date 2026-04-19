#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include "texture.h"
#include <string>

class TextureLoader
{
public:
    static Texture load(const std::string& path);

private:


};

#endif