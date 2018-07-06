#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "Primitive.h"

#include <string>
#include <vector>

namespace Infinity{

    class Material;

    class Surface
    {
        public:
            Surface();
            ~Surface();

            // set and get surface name
            void setName(const char* name);
            const char* getName();

            // add surface vertices and indices
            void addVertices(const glm::vec3 &pos, const glm::vec3 &normal, const glm::vec4 &texcoord);
            void addVertices(const Vertex &vertex);
            void addIndices(unsigned int index);

            // render surface
            void renderSurface();

        private:
            // make sure that mesh can access private members and functions
            friend class Mesh;

            // configure vertex array buffer
            void configure();

            std::string                 m_name;         // surface name
            Material*                   m_material;     // surface material

            unsigned int m_vao_id;                      // vao id
            unsigned int m_vbo_id, m_ebo_id;            // vbo and ebo id

            std::vector<Vertex>         m_vertices;     // vertices
            std::vector<unsigned int>   m_indices;      // indices
    };
}

#endif//_SURFACE_H_