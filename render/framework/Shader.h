#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <glm/glm.hpp>

namespace Infinity{

    class Shader{
    public:
        Shader();
        Shader(const char *vertex, const char *fragment);
        ~Shader();

        // load shaders
        int loadVertex(const char *vertex);
        int loadFragMent(const char *fragment);

        // compile the shader
        int compile();

        // use and unuse the shader
        int bind();
        int unbind();
        unsigned int getProgramID();

        // set shader uniform value
        void setUniformBool(const char *name, bool value) const;
        void setUniformInt(const char *name, int value) const;
        void setUniformFloat(const char *name, float value) const;
        void setUniformVec3(const char *name, float x, float y, float z) const;
        void setUniformVec3(const char *name, const glm::vec3 &vec) const;
        void setUniformMat4(const char *name, const glm::mat4 &mat) const;

    private:
        // load and preprocess file
        std::string load(const char *name) const;

    private:
        unsigned int m_programID;

        std::string m_vertexCode;
        std::string m_fragmentCode;
    };

}

#endif//_SHADER_H_