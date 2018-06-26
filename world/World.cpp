#include "World.h"
#include "players/Player.h"

namespace Infinity{

    World::World()
    {
        m_player = new Player();
    }

    World::~World()
    {

    }

    Player* World::getPlayer()
    {
        return m_player;
    }
}