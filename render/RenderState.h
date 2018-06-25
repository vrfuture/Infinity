#ifndef _RENDER_STATE_H_
#define _RENDER_STATE_H_

#include <glm/glm.hpp>

namespace Infinity{

    class RenderState
    {
    public:
        RenderState();
        ~RenderState();

        // set view port
        virtual void setViewport(int x, int y, int width, int height);

        // set rendering backgound color
        virtual void setBackgroundColor(float r, float g, float b, float a);

        // set projection
        void setProjection(const glm::mat4 &proj);
        const glm::mat4& getProjection();

    private:
        // window size
        int m_windowWidth, m_windowHeight;

        // projection matrix
        glm::mat4 m_projection;
    };
}


#endif//_RENDER_STATE_H_