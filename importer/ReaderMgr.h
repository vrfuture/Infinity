#ifndef _READERMGR_H_
#define _READERMGR_H_

#include <string>

class aiNode;
class aiScene;
class aiMesh;
class aiMaterial;

namespace Infinity{

    class Mesh;
    class ObjectMesh;

    class ReaderMgr
    {
    public:
        ReaderMgr();
        ~ReaderMgr();

        // static class
        static ReaderMgr* getInstance();

        // load mesh model
        void loadMesh(const char *filename);

    private:
        // read node from the model file
        void  processNode(ObjectMesh *object, const aiNode *node, const aiScene *scene);

        // parse mesh and return mesh instance
        Mesh* processMesh(const aiMesh *ai_mesh, const aiScene *ai_scene);

        // read mesh material
        void readMaterial(Mesh *mesh, const aiMaterial* material);
        void readPolygons(Mesh *mesh, const aiMesh *ai_mesh);

        std::string m_directory;
    };
}

#endif