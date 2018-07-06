#include "Surface.h"
#include "engine/Infinity.h"
#include "render/framework/Material.h"

namespace Infinity{

    Surface::Surface()
    {

    }

    Surface::~Surface()
    {

    }

    void Surface::setName(const char* name)
    {
        m_name = name;
    }

    const char* Surface::getName()
    {
        return m_name.c_str();
    }

    void Surface::addVertices(const glm::vec3 &pos, const glm::vec3 &normal, const glm::vec4 &texcoord)
    {
        // create a vertex and assign value
        Vertex vertex;

        vertex.xyz      = pos;
        vertex.normal   = normal;
        vertex.texcoord = texcoord;

        // save vertex
        addVertices(vertex);
    }

    void Surface::addVertices(const Vertex &vertex)
    {
        m_vertices.push_back(vertex);
    }

    void Surface::addIndices(unsigned int index)
    {
        m_indices.push_back(index);
    }

    void Surface::renderSurface()
    {
        // bind vertex array buffer
        glBindVertexArray(m_vao_id);

        // bind and update shader before rendering
        m_material->bindShader();
        m_material->update();

        // draw objects with element indices
        glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
        m_material->unbindShader();

        glBindVertexArray(0);
    }

    void Surface::configure()
    {
        // create vertex array buffer
        glGenVertexArrays(1, &m_vao_id);
        glGenBuffers(1, &m_vbo_id);
        glGenBuffers(1, &m_ebo_id);

        glBindVertexArray(m_vao_id);
        // load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);

        glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        // vertex normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
        // vertex texture coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));

        glBindVertexArray(0);
    }

}