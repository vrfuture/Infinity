#ifndef _VISUALIZER_H_
#define _VISUALIZER_H_

#include <glm/glm.hpp>
#include <vector>

namespace Infinity{

    class Shader;

    class Visualizer
    {
    public:
        Visualizer();
        ~Visualizer();

        void setProjection(const glm::mat4 &projection);
        void setModelView(const glm::mat4 &modelView);

        void renderPrimitives();

        struct Vertex
        {
            glm::vec3 xyz;      // position
            glm::vec3 normal;   // normal
            glm::vec4 texcoord; // texture coordinates or color
        };

        // render 3d triangles
        void renderTriangles3D(const glm::vec3 &v0,const glm::vec3 &v1,const glm::vec3 &v2,const glm::vec4 &color);
        void renderTriangles3D(const Vertex &p0, const Vertex &p1, const Vertex &p2);

        struct Triangle {
			glm::vec3 xyz[3];		        // triangle vertices
            glm::vec2 texcoord;             // texture coordiante
			glm::vec4 color;		        // triangle color
		};

    private:
        void render_triangles();
        void initDefaultVAO();

        glm::mat4 m_projection;
        glm::mat4 m_modelView;

        // base shader
        Shader *m_shaderDefault;
        Shader *m_shaderModel;

        // variable members
        unsigned int vertex_vao_id;         // vao
		unsigned int vertex_vbo_id;         // vbo

        std::vector<Vertex> m_triangles;    // 3D triangles
    };
}

#endif//_VISUALIZER_H_