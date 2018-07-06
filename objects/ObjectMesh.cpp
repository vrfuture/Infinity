#include "ObjectMesh.h"
#include "framework/Mesh.h"
#include "render/framework/Material.h"
#include "render/framework/Shader.h"

#include <iostream>
#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>


namespace Infinity{

    ObjectMesh::ObjectMesh()
    {
        
    }

    ObjectMesh::ObjectMesh(const char* filename, bool gamma)
    {
        //loadMesh(filename);
    }

    ObjectMesh::~ObjectMesh()
    {
        std::vector<Mesh*>::iterator it = m_meshes.begin();
        while(it != m_meshes.end())
        {
            delete (*it);
            (*it) = NULL;
            it++;
        }
        m_meshes.clear();
    }

    void ObjectMesh::addMesh(Mesh* mesh)
    {
        if(NULL == mesh) return;

        // create vao nad vbo for the mesh
        mesh->setupMesh();

        // keep mesh in the vector
        m_meshes.push_back(mesh);
    }

    void ObjectMesh::render()
    {
        for(int i=0; i<m_meshes.size(); i++)
        {
            m_meshes[i]->renderMesh();
        }
    }
}