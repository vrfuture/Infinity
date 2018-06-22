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

        // render 3d triangles
        void renderTriangles3D(const glm::vec3 &v0,const glm::vec3 &v1,const glm::vec3 &v2,const glm::vec4 &color);

        struct Triangle {
			glm::vec3 xyz[3];		        // triangle vertices
			glm::vec4 color;		        // triangle color
			float distance;		            // distance
		};

    private:
        void render_triangles();
        void initBaseVAO();

        glm::mat4 m_projection;
        glm::mat4 m_modelView;

        // base shader
        Shader *m_shaderBase;
        unsigned int m_vaoBase;

        std::vector<Triangle> m_triangles;  // 3D triangles
    };
}

#endif//_VISUALIZER_H_