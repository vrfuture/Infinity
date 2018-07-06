#ifndef _MARERIALMANAGER_H_
#define _MARERIALMANAGER_H_

#include <vector>

namespace Infinity{

    class Material;

    class MaterialManager
    {
        public:
            static MaterialManager* getInstance();

            // find material
            Material* findMaterial(const char* name);

            // create material
            Material* createMaterial(const char* name, bool force = false);

        private:
            MaterialManager();
            ~MaterialManager();

            // material lists
            std::vector<Material*> m_materials;
    };
}


#endif//_MARERIALMANAGER_H_