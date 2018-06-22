#include "Visualizer.h"
#include "framework/Shader.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

#define VISUALIZER_NUM_LINES		(1024 * 2)
#define VISUALIZER_NUM_TRIANGLES	(1024 * 3)

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
        // bind vertex array buffer and update data
        glBindVertexArray(vertex_vao_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo_id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle) * m_triangles.size(), NULL, GL_STREAM_DRAW);

        // write data into cpu
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Triangle) * m_triangles.size(), &m_triangles[0]);

        m_triangles.clear();
    }

    void Visualizer::initBaseVAO()
    {
        // create vao and vbo
        glGenVertexArrays(1, &vertex_vao_id);
        glGenBuffers(1, &vertex_vbo_id);
        
        // bind vertex array buffer
        glBindVertexArray(vertex_vao_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo_id);

        // tell gpu the data type
        glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_STREAM_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindVertexArray(0);
    }
}