#ifndef _WORLD_H_
#define _WORLD_H_

namespace Infinity{

    class Player;

    class World{
    public:
        World();
        ~World();

        // get player of currrent world
        Player* getPlayer();

        void update();
    
    private:
        Player* m_player;
    };
}


#endif//_WORLD_H_