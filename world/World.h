#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>

namespace Infinity{

    class Player;
    class Node;

    class World{
    public:
        World();
        ~World();

        // append and remove node from the vector
        void addNode(Node *node);
        void removeNode(Node *node);

        // get player of currrent world
        Player* getPlayer();

        void update();
        void render();
    
    private:
        Player* m_player;               // world player
        std::vector<Node*> m_nodes;     // nodes in current world
    };
}


#endif//_WORLD_H_