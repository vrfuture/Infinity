#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#include <glm/glm.hpp>

namespace Infinity{

    class Player
    {
    public:
        Player();
        ~Player();

    private:
        glm::mat4 m_transform;
        
    };

}

#endif//_PLAYERS_H_

