#include "Player.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Infinity{

    Player::Player()
    {
        m_modelView = glm::lookAt(glm::vec3(0, 0, 2), glm::vec3(0,0,0), glm::vec3(0, 0, 1));
    }

    Player::~Player()
    {
        
    }

    const glm::mat4& Player::getModelView()
    {
        return m_modelView;
    }
}