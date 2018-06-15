#include "RenderState.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

namespace Infinity{

    RenderState::RenderState()
    {

    }

    RenderState::~RenderState()
    {

    }

    void RenderState::setViewport(int x, int y, int width, int height)
    {
        glViewport(x, y, width, height);
    }

    void RenderState::setBackgroundColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

}