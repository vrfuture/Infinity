#include "Visualizer.h"
#include "framework/Shader.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

namespace Infinity{

    Visualizer::Visualizer()
    {
        m_shaderBase = new Shader("data/core/shaders/base.vs", "data/core/shaders/base.fs");
        initBaseVAO();
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

        m_shaderBase->bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        m_shaderBase->unbind();
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
        
        m_triangles.clear();
    }

    void Visualizer::initBaseVAO()
    {
        glGenVertexArrays(1, &m_vaoBase);
        unsigned int vbo;
        glGenBuffers(1, &vbo);
        
        glBindVertexArray(m_vaoBase);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
}