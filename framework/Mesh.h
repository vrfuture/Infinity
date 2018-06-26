#ifndef _MESH_H_
#define _MESH_H_

#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace Infinity
{
    class Shader;
    class Mesh
    {
    public:
        struct Vertex
        {
            glm::vec3 xyz;          // vertex position
            glm::vec3 normal;       // vertex normal
            glm::vec4 texcoord;     // vertex texture coordinates
        };

        struct Texture
        {
            unsigned int tex_id;
            std::string tex_type;
            std::string tex_path;
        };

        Mesh();
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        ~Mesh();

        void renderMesh(Shader *shader);

    private:
        void setupMesh();

        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        unsigned int m_vao_id;
        unsigned int m_vbo_id, m_ebo_id;
    };
}

#endif//_MESH_H_