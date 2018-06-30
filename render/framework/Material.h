#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <map>
#include <string>

namespace Infinity{

    class Texture;
    class Shader;

    class Material
    {
    public:
        Material();
        ~Material();

        // update shader
        void update();

        // set material name
        void setName(const char* name);

        // get current shader
        Shader* getShader();

        // use and release remder shader
        void bindShader();
        void unbindShader();

        // load shader
        void loadShader(const char* vertex, const char* fragment);

        // append diffuse, normal and specular texture
        void appendTextureDiffuse(const char* image_file);
        void appendTextureNormal(const char* image_file);
        void appendTextureSpecular(const char* image_file);

    private: 
        Shader* m_shader;        // material shader

        std::string m_name;      // material name
        std::map<std::string, Texture*> m_textures; // textures map list
    };
}

#endif//_MATERIAL_H_