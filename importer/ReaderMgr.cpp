#include "ReaderMgr.h"

#include "engine/engine.h"
#include "framework/Mesh.h"
#include "objects/ObjectMesh.h"
#include "render/framework/Material.h"
#include "world/World.h"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <iostream>
#include <string>

namespace Infinity{

    ReaderMgr::ReaderMgr()
    {

    }

    ReaderMgr::~ReaderMgr()
    {

    }

    ReaderMgr* ReaderMgr::getInstance()
    {
        static ReaderMgr _instance;
        return &_instance;
    }

    void ReaderMgr::loadMesh(const char *filename)
    {
        // read model file via assimp
        Assimp::Importer importer;
        const aiScene* _scene = importer.ReadFile(filename, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

        // check for errors
        if(!_scene || _scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !_scene->mRootNode) // if is Not Zero
        {
            std::cout << "ERROR::ReaderMgr::loadMesh:: " << importer.GetErrorString() << std::endl;
            return;
        }
        // retrieve the directory path of the filepath
        std::string _path = filename;
        m_directory = _path.substr(0, _path.find_last_of('/'));

        // create mesh instance
        ObjectMesh* _objMesh = new ObjectMesh();

        // process ASSIMP's root node recursively
        processNode(_objMesh, _scene->mRootNode, _scene);

        // add loaded object mesh to the world
        engine.world->addNode(_objMesh);
        
        // reset directory path to null
        m_directory = "";
    }

    void ReaderMgr::processNode(ObjectMesh *object, const aiNode *node, const aiScene *scene)
    {
        // process each mesh located at the current node
        for(unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            // the node object only contains indices to index the actual objects in the scene. 
            // the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

            // read mesh data
            object->addMesh(processMesh(mesh, scene));
        }
        // after we've processed all of the meshes (if any) we then recursively process each of the children nodes
        for(unsigned int i = 0; i < node->mNumChildren; i++)
        {
            processNode(object, node->mChildren[i], scene);
        }
    }

    Mesh* ReaderMgr::processMesh(const aiMesh *ai_mesh, const aiScene *ai_scene)
    {
        // create mesh
        Mesh *_mesh = new Mesh();
        _mesh->setName(ai_mesh->mName.C_Str());

        // read mesh vertices, normals and texture coordinates
        readPolygons(_mesh, ai_mesh);

        // read mesh material textures
        aiMaterial* material = ai_scene->mMaterials[ai_mesh->mMaterialIndex];
        if(material)
        {
            readMaterial(_mesh, material);
        }
        
        return _mesh;
    }

    void ReaderMgr::readPolygons(Mesh *mesh, const aiMesh *ai_mesh)
    {
        // we declare a placeholder vector since assimp uses its own vector class that doesn't directly
        // convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
        glm::vec3 vector; 

         // Walk through each of the mesh's vertices
        for(unsigned int i = 0; i < ai_mesh->mNumVertices; i++)
        {
            // create mesh vertex
            Mesh::Vertex vertex;
            // positions
            vector.x = ai_mesh->mVertices[i].x;
            vector.y = ai_mesh->mVertices[i].y;
            vector.z = ai_mesh->mVertices[i].z;
            vertex.xyz = vector;

            // normals
            vector.x = ai_mesh->mNormals[i].x;
            vector.y = ai_mesh->mNormals[i].y;
            vector.z = ai_mesh->mNormals[i].z;
            vertex.normal = vector;
            
            // texture coordinates
            if(ai_mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
            {
                // a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
                // use models where a vertex can have multiple texture coordinates so we always take the first set (0).
                vertex.texcoord.x = ai_mesh->mTextureCoords[0][i].x; 
                vertex.texcoord.y = ai_mesh->mTextureCoords[0][i].y;
            }
            else
            {
                vertex.texcoord = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
            }
            mesh->addVertices(vertex);
        }

        // now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
        for(unsigned int i = 0; i < ai_mesh->mNumFaces; i++)
        {
            aiFace& face = ai_mesh->mFaces[i];
            // retrieve all indices of the face and store them in the indices vector
            for(unsigned int j = 0; j < face.mNumIndices; j++)
            {
                mesh->addIndices(face.mIndices[j]);
            }
        }
    }

    void ReaderMgr::readMaterial(Mesh *mesh, const aiMaterial* material)
    {
        // we assume a convention for sampler names in the shaders. Each diffuse texture should be named
        // as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
        
        // use to store material texture name
        aiString str;

        // 1. diffuse maps
        for(unsigned int i = 0; i < material->GetTextureCount(aiTextureType_DIFFUSE); i++)
        {
            material->GetTexture(aiTextureType_DIFFUSE, i, &str);
            mesh->getMaterial()->appendTextureDiffuse((m_directory + '/' +  str.C_Str()).c_str());
        }

        // 2. normal maps
        for(unsigned int i = 0; i < material->GetTextureCount(aiTextureType_NORMALS); i++)
        {
            material->GetTexture(aiTextureType_NORMALS, i, &str);
            mesh->getMaterial()->appendTextureNormal((m_directory + '/' +  str.C_Str()).c_str());
        }

        // 3. specular maps
        for(unsigned int i = 0; i < material->GetTextureCount(aiTextureType_SPECULAR); i++)
        {
            material->GetTexture(aiTextureType_SPECULAR, i, &str);
            mesh->getMaterial()->appendTextureSpecular((m_directory + '/' +  str.C_Str()).c_str());
        }
    }
}