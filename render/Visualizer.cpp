#include "Visualizer.h"

namespace Infinity{

    Visualizer::Visualizer()
    {

    }

    Visualizer::~Visualizer()
    {

    }

     void Visualizer::setProjection(const glm::mat4 &projection)
     {
         m_projection = projection;
     }

    void Visualizer::setModelView(const glm::mat4 &modelView)
    {
        m_modelView = modelView;
    }

    void Visualizer::renderPrimitives()
    {
        if(m_triangles.size() > 0) render_triangles();
    }

    void Visualizer::renderTriangles3D(const glm::vec3 &v0,const glm::vec3 &v1,const glm::vec3 &v2,const glm::vec4 &color)
    {
        Triangle t;

        // vertices of the triangles
	    t.xyz[0] = v0;
	    t.xyz[1] = v1;
	    t.xyz[2] = v2;

        // color
        t.color = color;
        m_triangles.push_back(t);
    }

    void Visualizer::render_triangles()
    {

    }
}