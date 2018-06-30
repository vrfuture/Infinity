#include "Mesh.h"
#include "engine/engine.h"
#include "players/Player.h"
#include "render/RenderState.h"
#include "render/Render.h"
#include "render/framework/Shader.h"
#include "render/framework/Material.h"
#include "world/World.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>
#include <iostream>

namespace Infinity{

    Mesh::Mesh()
    {

    }

    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
    {
        this->vertices = vertices;
        this->indices  = indices;
        this->textures = textures;

        // set vertex buffers and its attribute pointers.
        setupMesh();

        // create new material
        m_material = new Material();
        m_material->loadShader("data/core/shaders/baseModel.vs", "data/core/shaders/baseModel.fs");
        m_material->setName("mesh_base");

        for(int i=0; i<textures.size(); i++)
        {
            std::string name = textures[i].tex_type;
            if(name == "texture_diffuse")
            {
                m_material->appendTextureDiffuse(textures[i].tex_path.c_str());
                break;
            }
        }
    }

    Mesh::~Mesh()
    {

    }

    Material* Mesh::getMaterial()
    {
        return m_material;
    }

    void Mesh::renderMesh(Shader *shader)
    {
        // bind vertex array buffer
        glBindVertexArray(m_vao_id);

        // bind and update shader before rendering
        m_material->bindShader();
        m_material->update();

        // draw objects with element indices
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        m_material->unbindShader();

        glBindVertexArray(0);
    }

    void Mesh::setupMesh()
    {
        // create vertex array buffer
        glGenVertexArrays(1, &m_vao_id);
        glGenBuffers(1, &m_vbo_id);
        glGenBuffers(1, &m_ebo_id);

        glBindVertexArray(m_vao_id);
        // load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

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