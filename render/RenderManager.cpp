#include "RenderManager.h"
#include "Render.h"
#include "engine/engine.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

namespace Infinity{

    unsigned int RenderManager::s_program_id = 0;
    RenderManager::RenderManager()
    {
        createRender();
    }

    RenderManager::~RenderManager()
    {
        delete engine.render;
        engine.render = nullptr;
    }

    void RenderManager::createRender() const
    {
        if(nullptr != engine.render)
        {
            return;
        }
        engine.render = new Render();
    }

    unsigned int RenderManager::getProgramID()
    {
        return s_program_id;
    }
    
    void RenderManager::setProgramID(unsigned int program)
    {
        if(s_program_id != program)
        {
            s_program_id = program;
            glUseProgram(program);
        }
    }
}