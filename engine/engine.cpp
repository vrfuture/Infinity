#include "engine.h"
#include "framework/App.h"
#include "render/RenderManager.h"
#include "render/RenderState.h"
#include "render/Render.h"

namespace Infinity{

    // engine defination
    EngineGlobals engine;

    Engine::Engine()
    {
        // create glfw based window app
        engine.app = new App();
    }

    Engine::~Engine()
    {
        delete engine.app;
        engine.app = nullptr;
    }

    void Engine::init()
    {
        engine.app->init();
    }

    void Engine::mainloop()
    {
        // iterate update render and swap if window is not closed
        while(!engine.app->shouldAppClose())
        {
            engine.app->update();
            update();
            engine.app->render();
            render();
            engine.app->swap();
            swap();
        }
    }

    void Engine::update()
    {

    }

    void Engine::render()
    {
        // set render viewport
        RenderState *state = engine.render->getRenderState();
        state->setViewport(0, 0, engine.app->getWidth(), engine.app->getHeight());

        // render world
        engine.render->renderWorld();
    }

    void Engine::swap()
    {

    }

    void Engine::shutdown()
    {
        engine.app->shutdown();
    }

    // Engine global struct to collect variables=========================================
    void initEngine()
    {
        // create engine and init
        engine.engine = new Engine();
        engine.engine->init();

        // create render manager instance
        engine.renderManager = new RenderManager();

        // operators after engine initialzation
        RenderState *_state = engine.render->getRenderState();
        _state->setBackgroundColor(1.0f, 0.0f, 0.0f, 1.0f);
    }

    // destory engine and collect resources
    void shutdownEngine()
    {
        // close
        engine.engine->shutdown();

        // destory the engine
        delete engine.engine;
        engine.engine = nullptr;

        delete engine.renderManager;
        engine.renderManager = nullptr;
    }
}