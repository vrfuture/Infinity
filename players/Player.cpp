#include "Player.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Infinity{

    Player::Player()
    {
        // default model view
        m_modelView  = glm::lookAt(glm::vec3(0, 20, 20), glm::vec3(0, 10, 0), glm::vec3(0, 1, 0));

        // dummy player by default
        m_playerType = PLAYER_DUMMY;
    }

    Player::~Player()
    {
        
    }

    int Player::getType()
    {
        return m_playerType;
    }

    const glm::mat4& Player::getModelView()
    {
        return m_modelView;
    }

    void Player::update()
    {
        
    }
}