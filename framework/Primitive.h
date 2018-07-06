#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include <glm/glm.hpp>

namespace Infinity{

    // vertex primitives in graphic rendering
    struct Vertex
    {
        glm::vec3 xyz;          // vertex position
        glm::vec3 normal;       // vertex normal
        glm::vec4 texcoord;     // vertex texture coordinates
    };
}

#endif//_PRIMITIVE_H_