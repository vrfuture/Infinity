#include "PlayerOrbit.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Infinity{

    PlayerOrbit::PlayerOrbit()
    {
        m_alpha  = 0.0f;
        m_theta  = -180.0f;

        m_radius = 1.0f;
    }

    PlayerOrbit::~PlayerOrbit()
    {
        
    }

    void PlayerOrbit::update()
    {
        glm::vec3 position = 


        m_modelView = glm::lookAt(position, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    }
}