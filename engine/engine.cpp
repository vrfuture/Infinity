#include "engine.h"
#include "framework/App.h"

namespace Infinity{

    // engine defination
    EngineGlobals engine;

    Engine::Engine()
    {
        // create glfw window app
        engine.app = new Framework::App();
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
            engine.app->render();
            engine.app->swap();
        }
    }

    void Engine::update()
    {

    }

    void Engine::render()
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