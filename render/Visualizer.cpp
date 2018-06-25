#include "Visualizer.h"
#include "framework/Shader.h"
#include "framework/Texture.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

#define VISUALIZER_NUM_LINES		(1024 * 2)
#define VISUALIZER_NUM_TRIANGLES	(1024 * 3)

namespace Infinity{

    Texture *texture = NULL;

    Visualizer::Visualizer()
    {
        m_shaderDefault = new Shader("data/core/shaders/baseTexture.vs", "data/core/shaders/baseTexture.fs");

        texture = new Texture();
        texture->load("data/core/textures/img_cheryl.jpg");
        initDefaultVAO();
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
        // first vertex of a triangle
        Vertex v;
        v.xyz   = v0;
        v.texcoord = color;
        m_triangles.push_back(v);

        // second vertex
        v.xyz   = v1;
        m_triangles.push_back(v);

        // third vertex
        v.xyz   = v2;
        m_triangles.push_back(v);
    }

    void Visualizer::renderTriangles3D(const Vertex &p0, const Vertex &p1, const Vertex &p2)
    {
        m_triangles.push_back(p0);
        m_triangles.push_back(p1);
        m_triangles.push_back(p2);
    }

    void Visualizer::render_triangles()
    {
        // bind texture
        glBindTexture(GL_TEXTURE_2D, texture->getTextureID());

        // bind vertex array buffer and update data
        glBindVertexArray(vertex_vao_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo_id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_triangles.size(), NULL, GL_STREAM_DRAW);

        // write data into cpu
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * m_triangles.size(), &m_triangles[0]);

        // use base shader to draw cartoon triangle
        m_shaderDefault->bind();
        glDrawArrays(GL_TRIANGLES, 0, m_triangles.size());
        m_shaderDefault->unbind();

        // clear triangles vector
        m_triangles.clear();
    }

    void Visualizer::initDefaultVAO()
    {
        // create vao and vbo
        glGenVertexArrays(1, &vertex_vao_id);
        glGenBuffers(1, &vertex_vbo_id);
        
        // bind vertex array buffer
        glBindVertexArray(vertex_vao_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo_id);

        // tell gpu the data type
        glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_STREAM_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)24);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(2);
        glBindVertexArray(0);
    }
}