#include "Texture.h"

#include <SOIL.h>
#include <iostream>

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

namespace Infinity
{
    Texture::Texture()
    {
        m_texture_id = 0;
    }

    Texture::Texture(const char *filename)
    {
        m_texture_id = 0;
        load(filename);
    }

    Texture::~Texture()
    {

    }

    void Texture::load(const char *filename)
    {
        glGenTextures(1, &m_texture_id);

        int width, height, channels;
        unsigned char *data = SOIL_load_image(filename, &width, &height, &channels, 0);
        if(data)
        {
            glBindTexture(GL_TEXTURE_2D, m_texture_id);
            GLenum format;
            if (channels == 1)
                format = GL_RED;
            else if (channels == 3)
                format = GL_RGB;
            else if (channels == 4)
                format = GL_RGBA;
            
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            // configure texture parameters
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }
        else
        {
            std::cout << "Texture::Load: Failed to load image: "<< filename << std::endl;
        }

        SOIL_free_image_data(data);
    }

    unsigned int Texture::getTextureID()
    {
        return m_texture_id;
    }
}