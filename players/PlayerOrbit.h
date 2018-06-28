#ifndef _PLAYER_ORBIT_H_
#define _PLAYER_ORBIT_H_

#include "Player.h"

namespace Infinity{

    class PlayerOrbit : public Player
    {
    public:
        PlayerOrbit();
        ~PlayerOrbit();

        virtual void update();

        // get and set camera radius
        void  setRadius(float radius);
        float getRadius();

        // set rotation degree, along x axis
        void  setAlpha(float alpha);
        float getAlpha();

        // set rotation degree, along y axis
        void  setTheta(float theta);
        float getTheta();

    private:
        float m_alpha;      // rotation degree along x axis
        float m_theta;      // roattion degree along y axis

        float m_radius;     // robit camera radius

    };

}


#endif//_PLAYER_ORBIT_H_