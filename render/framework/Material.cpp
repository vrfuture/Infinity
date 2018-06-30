#include "Material.h"
#include "engine/engine.h"
#include "framework/Texture.h"
#include "render/Render.h"
#include "render/RenderState.h"
#include "render/framework/Shader.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

namespace Infinity
{
    #define TEXTURE_DIFFUSE  "tex_diffuse"
    #define TEXTURE_NORMAL   "tex_normal"
    #define TEXTURE_SPECULAR "tex_specular"

    Material::Material()
    {
        m_shader = new Shader();
    }

    Material::~Material()
    {

    }

    /// NOTES: shader must be binded before call this function
    void Material::update()
    {
        // configure textures
        int _indexTexture = 0;
        std::map<std::string, Texture*>::const_iterator it = m_textures.begin();
        while(it != m_textures.end())
        {
            glActiveTexture(GL_TEXTURE0 + _indexTexture);

            // configure shader texture
            //m_shader->setUniformInt(it->first.c_str(), _indexTexture);

            // bind texture
            glBindTexture(GL_TEXTURE_2D, it->second->getTextureID());
            it++;
            _indexTexture++;
        }

        // access shadr variable, we have to bind the shader first
        RenderState *state = engine.render->getRenderState();
        glm::mat4 _proj = state->getProjection();
        glm::mat4 _view = state->getModelView();

        // set model view and projection matrix of the shader
        m_shader->setUniformMat4("view", _view);
        m_shader->setUniformMat4("projection", _proj);
    }

    void Material::setName(const char* name)
    {
        m_name = name;
    }

    void Material::loadShader(const char* vertex, const char* fragment)
    {
        m_shader->load(vertex, fragment);
    }

     Shader* Material::getShader()
     {
         return m_shader;
     }

     void Material::bindShader()
     {
         m_shader->bind();
     }

     void Material::unbindShader()
     {
         m_shader->unbind();
     }

    void Material::appendTextureDiffuse(const char* image_file)
    {
        // create new texture
        Texture *_texture = new Texture(image_file);

        // find diffuse texture in the map
        std::map<std::string, Texture*>::iterator it = m_textures.find(TEXTURE_DIFFUSE);
        if(it == m_textures.end())
        {
            m_textures.insert(std::pair<std::string, Texture*>(TEXTURE_DIFFUSE, _texture));
        }
        else
        {
            delete it->second;
            it->second = _texture;
        }
    }

    void Material::appendTextureNormal(const char* image_file)
    {
        // create new texture
        Texture *_texture = new Texture(image_file);

        // find diffuse texture in the map
        std::map<std::string, Texture*>::iterator it = m_textures.find(TEXTURE_NORMAL);
        if(it == m_textures.end())
        {
            m_textures.insert(std::pair<std::string, Texture*>(TEXTURE_NORMAL, _texture));
        }
        else
        {
            delete it->second;
            it->second = _texture;
        }
    }
    void Material::appendTextureSpecular(const char* image_file)
    {
        // create new texture
        Texture *_texture = new Texture(image_file);

        // find diffuse texture in the map
        std::map<std::string, Texture*>::iterator it = m_textures.find(TEXTURE_SPECULAR);
        if(it == m_textures.end())
        {
            m_textures.insert(std::pair<std::string, Texture*>(TEXTURE_SPECULAR, _texture));
        }
        else
        {
            delete it->second;
            it->second = _texture;
        }
    }
}