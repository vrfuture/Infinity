#include "World.h"
#include "players/PlayerOrbit.h"

namespace Infinity{

    World::World()
    {
        m_player = new PlayerOrbit();
    }

    World::~World()
    {

    }

    Player* World::getPlayer()
    {
        return m_player;
    }

    void World::update()
    {
        m_player->update();
    }
}