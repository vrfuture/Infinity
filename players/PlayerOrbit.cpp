#include "PlayerOrbit.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Infinity{

    PlayerOrbit::PlayerOrbit()
    {
        m_alpha  =  0.0f;
        m_theta  = -90.0f;

        m_radius = 20.0f;
    }

    PlayerOrbit::~PlayerOrbit()
    {
        
    }

    void PlayerOrbit::update()
    {
        glm::vec3 position;
        position.x = m_radius * cos(glm::radians(m_alpha)) * cos(glm::radians(m_theta));
        position.y = m_radius * sin(glm::radians(m_alpha));
        position.z = m_radius * cos(glm::radians(m_alpha)) * sin(glm::radians(m_theta));

        m_modelView = glm::lookAt(position, glm::vec3(0, 10, 0), glm::vec3(0, 1, 0));
    }

    void PlayerOrbit::setRadius(float radius)
    {
        m_radius = radius;
    }

    float PlayerOrbit::getRadius()
    {
        return m_radius;
    }

    void PlayerOrbit::setAlpha(float alpha)
    {
        m_alpha = alpha;

        // limit rotation degree scale
        if(m_alpha > 89.0f)
        {
            m_alpha =  89.0f;
        }
        else if(m_alpha < -89.0f)
        {
            m_alpha = -89.0f;
        }
    }

    float PlayerOrbit::getAlpha()
    {
        return m_alpha;
    }

    void  PlayerOrbit::setTheta(float theta)
    {
        m_theta = theta;
    }

    float PlayerOrbit::getTheta()
    {
        return m_theta;
    }
}