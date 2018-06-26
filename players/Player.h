#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#include <glm/glm.hpp>

namespace Infinity{

    class Player
    {
    public:
        Player();
        ~Player();

        const glm::mat4& getModelView();

    private:
        glm::mat4 m_modelView;
    };

}

#endif//_PLAYERS_H_

