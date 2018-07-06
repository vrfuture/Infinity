#include "World.h"
#include "Node.h"
#include "players/PlayerOrbit.h"

namespace Infinity{

    World::World()
    {
        m_player = new PlayerOrbit();
    }

    World::~World()
    {
        std::vector<Node*>::iterator it = m_nodes.begin();
        while(it != m_nodes.end())
        {
            delete (*it);
            (*it) = NULL;
            it++;
        }
        m_nodes.clear();
    }

    void World::addNode(Node *node)
    {
        if(NULL == node || std::find(m_nodes.begin(), m_nodes.end(), node) != m_nodes.end()) return;

        m_nodes.push_back(node);
    }

    void World::removeNode(Node *node)
    {
        std::vector<Node*>::iterator it = std::find(m_nodes.begin(), m_nodes.end(), node);
        if(it != m_nodes.end())
        {
            m_nodes.erase(it);
        }
    }

    Player* World::getPlayer()
    {
        return m_player;
    }

    void World::update()
    {
        m_player->update();

        std::vector<Node*>::iterator it = m_nodes.begin();
        while(it != m_nodes.end())
        {
            (*it)->update();
            it++;
        }
    }

     void World::render()
     {
        std::vector<Node*>::iterator it = m_nodes.begin();
        while(it != m_nodes.end())
        {
            (*it)->render();
            it++;
        }
     }
}