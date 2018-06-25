#ifndef _TEXTURE_H_
#define _TEXTURE_H_

namespace Infinity
{
    class Texture
    {
    public:
        Texture();
        ~Texture();

        // load texture from image file
        void load(const char *filename);

        // get texture id
        unsigned int getTextureID();

    private:
        unsigned int m_texture_id;

    };
}

#endif//_TEXTURE_H_