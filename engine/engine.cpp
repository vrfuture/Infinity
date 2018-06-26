#include "engine.h"
#include "framework/App.h"
#include "render/RenderState.h"
#include "render/Render.h"
#include "render/Visualizer.h"
#include "world/World.h"

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

        delete engine.render;
        engine.render = nullptr;

        delete engine.visualizer;
        engine.visualizer = nullptr;

        delete engine.world;
        engine.world = nullptr;
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

        // render visualizer
        engine.visualizer->renderPrimitives();
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

        // create render
        engine.render = new Render();

        // create world
        engine.world = new World();

        // create visualizer
        engine.visualizer = new Visualizer();

        // operators after engine initialzation
        RenderState *_state = engine.render->getRenderState();
        _state->setBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    // destory engine and collect resources
    void shutdownEngine()
    {
        // close
        engine.engine->shutdown();

        // destory the engine
        delete engine.engine;
        engine.engine = nullptr;
    }
}