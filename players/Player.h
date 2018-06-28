#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#include <glm/glm.hpp>

namespace Infinity{

    class Player
    {
    public:
        // player type
        enum PLYER_TYPE {
            PLAYER_DUMMY = 0,
            PLYAER_ORBIT,
            PLAYER_FREE,
        };

        Player();
        ~Player();

        // get player type
        int getType();

        // get model view
        const glm::mat4& getModelView();

        // update model view of the player
        virtual void update();

    protected:
        // model view of the player
        glm::mat4 m_modelView;

        // camera type, dummy, free or orbit
        int m_playerType;
    };

}

#endif//_PLAYERS_H_

