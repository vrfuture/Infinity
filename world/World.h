#ifndef _WORLD_H_
#define _WORLD_H_

namespace Infinity{

    class Player;

    class World{
    public:
        World();
        ~World();

        Player* getPlayer();
    
    private:
        Player* m_player;
    };
}


#endif//_WORLD_H_