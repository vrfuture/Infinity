#include "MaterialManager.h"
#include "Material.h"

namespace Infinity{

    MaterialManager::MaterialManager()
    {

    }

    MaterialManager::~MaterialManager()
    {

    }

    MaterialManager* MaterialManager::getInstance()
    {
        static MaterialManager _instance;
        return &_instance;
    }

    Material* MaterialManager::findMaterial(const char* name)
    {
        std::vector<Material*>::iterator it = m_materials.begin();
        while(it != m_materials.end())
        {
            if((*it)->getName() == name)
            {
                return (*it);
            }
            it++;
        }
        return nullptr;
    }

    Material* MaterialManager::createMaterial(const char* name, bool force)
    {
        std::vector<Material*>::iterator it = m_materials.begin();
        while(it != m_materials.end())
        {
            if((*it)->getName() == name)
            {
                if(false == force)
                {
                    return (*it);
                }
                else
                {
                    static std::string _new_name;
                    _new_name = name;
                    _new_name = _new_name + std::string("n1");
                    name = _new_name.c_str();
                    break;
                }
            }
            it++;
        }
        // create new matrerial and append it into the vector
        Material* _mat = new Material();
        _mat->setName(name);

        m_materials.push_back(_mat);
        return _mat;
    }
}