#ifndef _PLAYER_ORBIT_H_
#define _PLAYER_ORBIT_H_

#include "Player.h"

namespace Infinity{

    class PlayerOrbit : public Player
    {
    public:
        PlayerOrbit();
        ~PlayerOrbit();

        void update();

    private:
        float m_alpha;      // rotation degree along x axis
        float m_theta;      // roattion degree along y axis

        float m_radius;     // robit camera radius

    };

}


#endif//_PLAYER_ORBIT_H_