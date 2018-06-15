#include "RenderManager.h"
#include "Render.h"
#include "engine/engine.h"

namespace Infinity{

    RenderManager::RenderManager()
    {
        createRender();
    }

    RenderManager::~RenderManager()
    {
        delete engine.render;
        engine.render = nullptr;
    }

    void RenderManager::createRender() const
    {
        if(nullptr != engine.render)
        {
            return;
        }
        engine.render = new Render();
    }
}