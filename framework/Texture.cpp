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
    Texture::~Texture()
    {

    }

    void Texture::load(const char *filename)
    {
        // load an image file directly as a new OpenGL texture
        
        //m_texture_id = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO,  SOIL_CREATE_NEW_ID,
		 //                                    SOIL_FLAG_INVERT_Y);

        glGenTextures(1, &m_texture_id);
        glBindTexture(GL_TEXTURE_2D, m_texture_id);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        

        int width, height, channels;
        unsigned char *data = SOIL_load_image(filename, &width, &height, &channels, 0);
        if(data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            //glGenerateMipMap(GL_TEXTURE_2D);
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