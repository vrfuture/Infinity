#include "Shader.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

#include <fstream>
#include <sstream>
#include <iostream>

#define GL_SHADER_INFO_LOG_SIZE		32768

namespace Infinity{

    Shader::Shader()
    {
        m_programID = 0;
    }

    Shader::Shader(const char *vertex, const char *fragment)
    {
        m_programID = 0;

        load(vertex, fragment);
    }

    Shader::~Shader()
    {
        glDeleteShader(m_programID);
    }

    unsigned int Shader::getProgramID()
    {
        return m_programID;
    }

    int Shader::bind()
    {
        if(m_programID)
        {
            glUseProgram(m_programID);
        }
    }

    int Shader::unbind()
    {
        if(m_programID)
        {
            glUseProgram(0);
        }
    }

    int Shader::loadVertex(const char *vertex)
    {
        // vertex shader code
        m_vertexCode = load(vertex);
        const char *_vShaderCode = m_vertexCode.c_str();

        // create shader
	    GLuint _vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(_vertexShader, 1, &_vShaderCode, NULL);
        glCompileShader(_vertexShader);

        // compile status
        GLint _status = 0;
        glGetShaderiv(_vertexShader, GL_COMPILE_STATUS, &_status);
        if(_status == GL_FALSE)
        {
            char _info[GL_SHADER_INFO_LOG_SIZE];
            glGetShaderInfoLog(_vertexShader, sizeof(_info), NULL, _info);
            std::cout << "ERROR::SHADER::LOADVERTEX::" << _info << std::endl;
            glDeleteShader(_vertexShader);
            return 0;
        }

        // attach shader
        if(0 == m_programID) m_programID = glCreateProgram();
        glAttachShader(m_programID, _vertexShader);
        glDeleteShader(_vertexShader);
        return 1;
    }

    int Shader::loadFragMent(const char *fragment)
    {
        // load shader file
        m_fragmentCode = load(fragment);
        const char *_fShaderCode = m_fragmentCode.c_str();

        // create shader
	    GLuint _fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(_fragmentShader, 1, &_fShaderCode, NULL);
        glCompileShader(_fragmentShader);

        // compile status
        GLint _status = 0;
        glGetShaderiv(_fragmentShader, GL_COMPILE_STATUS, &_status);
        if(_status == GL_FALSE)
        {
            char _info[GL_SHADER_INFO_LOG_SIZE];
            glGetShaderInfoLog(_fragmentShader, sizeof(_info), NULL, _info);
            std::cout << "ERROR::SHADER::LOADVERTEX::" << _info << std::endl;
            glDeleteShader(_fragmentShader);
            return 0;
        }

        // attach shader
        if(0 == m_programID) m_programID = glCreateProgram();
        glAttachShader(m_programID, _fragmentShader);
        glDeleteShader(_fragmentShader);
        return 1;
    }

    void Shader::load(const char* vertex, const char* fragment)
    {
        if(vertex) loadVertex(vertex);
        if(fragment) loadFragMent(fragment);

        // compile the shader
        compile();;
    }

    int Shader::compile()
    {
        if(m_programID)
        {
            // lonk program
            GLint _status = 0;
            glLinkProgram(m_programID);
            glGetProgramiv(m_programID, GL_LINK_STATUS, &_status);
            if(GL_FALSE == _status)
            {
                char _info[GL_SHADER_INFO_LOG_SIZE];
                glGetProgramInfoLog(m_programID, sizeof(_info), NULL, _info);

                std::cout << "ERROR::SHADER::COMPILE::" << _info << std::endl;
                glDeleteShader(m_programID);
                m_programID = 0;
                return 0;
            }
            return 1;
        }
    }

    std::string Shader::load(const char *name) const
    {
        // source buffer
        std::ifstream _fileShader;
        _fileShader.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open file
            _fileShader.open(name);
            std::stringstream _streamShader;

            // read file data into stream
            _streamShader << _fileShader.rdbuf();

            // close file
            _fileShader.close();

            // convert string stream into string
            return _streamShader.str();
        }
        catch(std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::LOAD::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
    }

    void Shader::setUniformBool(const char *name, bool value) const
    {
        if(m_programID)
        {
            int _index = glGetUniformLocation(m_programID, name);
            if(-1 == _index)
            {
                std::cout<< "Shader::setUniformBool " << "cannot find uniform :" <<name << std::endl;
                return;
            }
            glUniform1i(_index, (int)value);
        }
    }

    void Shader::setUniformInt(const char *name, int value) const
    {
        if(m_programID)
        {
            int _index = glGetUniformLocation(m_programID, name);
            if(-1 == _index)
            {
                std::cout<< "Shader::setUniformFloat " << "cannot find uniform :" <<name << std::endl;
                return;
            }
            glUniform1i(_index, value);
        }
    }

    void Shader::setUniformFloat(const char *name, float value) const
    {
        if(m_programID)
        {
            int _index = glGetUniformLocation(m_programID, name);
            if(-1 == _index)
            {
                std::cout<< "Shader::setUniformFloat " << "cannot find uniform :" <<name << std::endl;
                return;
            }
            glUniform1f(_index, value);
        }
    }

    void Shader::setUniformVec3(const char *name, float x, float y, float z) const
    {
        if(m_programID)
        {
            int _index = glGetUniformLocation(m_programID, name);
            if(-1 == _index)
            {
                std::cout<< "Shader::setUniformVec3 " << "cannot find uniform :" <<name << std::endl;
                return;
            }
            glUniform3f(_index, x, y, z);
        }
    }

    void Shader::setUniformVec3(const char *name, const glm::vec3 &vec) const
    {
        if(m_programID)
        {
            int _index = glGetUniformLocation(m_programID, name);
            if(-1 == _index)
            {
                std::cout<< "Shader::setUniformVec3 " << "cannot find uniform :" <<name << std::endl;
                return;
            }
            glUniformMatrix3fv(_index, 1, GL_FALSE, &vec[0]);
        }
    }

    void Shader::setUniformMat4(const char *name, const glm::mat4 &mat) const
    {
        if(m_programID)
        {
            int _index = glGetUniformLocation(m_programID, name);
            if(-1 == _index)
            {
                std::cout<< "Shader::setUniformMat4 " << "cannot find uniform :" <<name << std::endl;
                return;
            }
            glUniformMatrix4fv(_index, 1, GL_FALSE, &mat[0][0]);

        }
    }
}