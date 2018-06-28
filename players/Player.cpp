#include "Player.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Infinity{

    Player::Player()
    {
        m_modelView = glm::lookAt(glm::vec3(0, 20, 20), glm::vec3(0, 10, 0), glm::vec3(0, 1, 0));
    }

    Player::~Player()
    {
        
    }

    const glm::mat4& Player::getModelView()
    {
        return m_modelView;
    }

    void Player::update()
    {
        
    }
}