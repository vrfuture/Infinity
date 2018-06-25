#ifndef _OBJECTMESH_H_
#define _OBJECTMESH_H_

#include "framework/Mesh.h"

#include <vector>
#include <string>
#include <assimp/scene.h>

class aiNode;
class aiScene;
class aiMesh;

namespace Infinity{

    class ObjectMesh
    {
    public:
        ObjectMesh(const char* filename, bool gamma = false);
        ~ObjectMesh();

        void renderMesh();

    private:
        void loadMesh(const char *filename);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Mesh::Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
        unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

        std::vector<Mesh::Texture> m_textureLoaded;
        std::vector<Mesh> m_meshes;
        std::string m_directory;
    };
}

#endif//_OBJECTMESH_H_