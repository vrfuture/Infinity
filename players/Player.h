#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#include <glm/glm.hpp>

namespace Infinity{

    class Player
    {
    public:
        Player();
        ~Player();

        // get model view
        const glm::mat4& getModelView();

        // update model view of the player
        virtual void update();

    protected:
        glm::mat4 m_modelView;
    };

}

#endif//_PLAYERS_H_

