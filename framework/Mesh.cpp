#include "Mesh.h"
#include "engine/engine.h"
#include "render/framework/Shader.h"
#include "players/Player.h"
#include "render/RenderState.h"
#include "render/Render.h"
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
    }

    Mesh::~Mesh()
    {

    }

    void Mesh::renderMesh(Shader *shader)
    {
        // bind appropriate textures
        unsigned int diffuseNr  = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr   = 1;
        unsigned int heightNr   = 1;
        for(int i=0; i<textures.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            std::string number;
            std::string name = textures[i].tex_type;
            if(name == "texture_diffuse"){
                number = std::to_string(diffuseNr++);
                /*
            else if (name == "texture_specular"){
                number = std::to_string(specularNr++);
                continue;
            }
            else if(name == "texture_normal")
                number = std::to_string(normalNr++);
            else if(name == "texture_height")
                number = std::to_string(heightNr++);
                */

            //glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);
            //shader->setUniformInt((name + number).c_str(), i);
            // and finally bind the texture
            glBindTexture(GL_TEXTURE_2D, textures[i].tex_id);
            }
        }
        // draw mesh
        glBindVertexArray(m_vao_id);

        shader->bind();
        RenderState *state = engine.render->getRenderState();
        glm::mat4 _proj = state->getProjection();
        glm::mat4 _view = engine.world->getPlayer()->getModelView();

        shader->setUniformMat4("view", _view);
        shader->setUniformMat4("projection", _proj);

        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        shader->unbind();

        glBindVertexArray(0);

        // always good practice to set everything back to defaults once configured.
        glActiveTexture(GL_TEXTURE0);
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