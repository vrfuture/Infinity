#include "Render.h"
#include "RenderState.h"
#include "Visualizer.h"

#include "engine/engine.h"

namespace Infinity{

    Render::Render()
    {
        m_renderState = new RenderState();
    }

    Render::~Render()
    {

    }

    void Render::renderWorld()
    {
        glm::vec3 p0(-0.5f, -0.5f, 0.0f);
        glm::vec3 p1(0.5f, -0.5f, 0.0f);
        glm::vec3 p2(0.0f, 0.5f, 0.0f);

        engine.visualizer->renderTriangles3D(p0, p1, p2, glm::vec4(1,1,1,1));
    }

}