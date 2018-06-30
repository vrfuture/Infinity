#include "RenderState.h"

#include "engine/engine.h"
#include "world/World.h"
#include "players/Player.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Infinity{

    RenderState::RenderState()
    {
        m_windowWidth  = 0;
        m_windowHeight = 0;
    }

    RenderState::~RenderState()
    {

    }

    void RenderState::setViewport(int x, int y, int width, int height)
    {
        // return directly if window size not changed
        if(width == m_windowWidth && height == m_windowHeight)
        {
            return;
        }

        glViewport(x, y, width, height);

        // recalculate view projection matrix
        m_projection = glm::perspective(glm::radians(45.0f), float(width) / float(height), 0.01f, 1000.0f);
        //m_projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

        // record window size
        m_windowWidth  = width;
        m_windowHeight = height;
        
    }

    void RenderState::setBackgroundColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void RenderState::setProjection(const glm::mat4 &proj)
    {
        m_projection = proj;
    }

    const glm::mat4& RenderState::getProjection()
    {
        return m_projection;
    }

    const glm::mat4& RenderState::getModelView()
    {
        return engine.world->getPlayer()->getModelView();
    }

}