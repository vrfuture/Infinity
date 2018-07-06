#ifndef _OBJECTMESH_H_
#define _OBJECTMESH_H_

#include "world/Node.h"

#include <vector>
#include <string>
#include <assimp/scene.h>

class aiNode;
class aiScene;
class aiMesh;

namespace Infinity{

    class Shader;
    class Mesh;

    class ObjectMesh : public Node
    {
    public:
        ObjectMesh();
        ObjectMesh(const char* filename, bool gamma = false);
        virtual ~ObjectMesh();

        // add mesh into the vector
        void addMesh(Mesh* mesh);

        void render();

    private:
        std::vector<Mesh*> m_meshes;
    };
}

#endif//_OBJECTMESH_H_