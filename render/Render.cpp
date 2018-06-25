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

        Visualizer::Vertex v0, v1, v2;
        // red vertex
        v0.xyz = p0;
        v0.texcoord = glm::vec4(0, 0, 0, 1);
        // green vertex
        v1.xyz = p1;
        v1.texcoord = glm::vec4(1, 0, 0, 1);
        // blue vertex
        v2.xyz = p2;
        v2.texcoord = glm::vec4(0.5, 1, 1, 1);

        engine.visualizer->renderTriangles3D(v0, v1, v2);
        //engine.visualizer->renderTriangles3D(p0, p1, p2, glm::vec4(1,1,0,1));
    }

}