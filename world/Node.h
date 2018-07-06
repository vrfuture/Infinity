#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <glm/glm.hpp>

namespace Infinity
{
    class Node
    {
    public:
        Node();
        virtual ~Node();

        // node update
        virtual void update();
        virtual void render();

        // get world transform
        const glm::mat4& getWorldTransform();

    private:
        std::string m_name;               // node name
        glm::mat4 m_world_transform;      // node world transform
    }; 
}

#endif//_NODE_H_