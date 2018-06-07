#include "engine.h"
#include "framework/App.h"

namespace Infinity{

    Engine::Engine() : m_app(nullptr)
    {
        m_app = new Framework::App();
    }

    Engine::~Engine()
    {

    }

    void Engine::init()
    {
        m_app->init();
    }

    void Engine::mainloop()
    {
        while(!m_app->shouldAppClose())
        {
            m_app->update();
            m_app->render();
            m_app->swap();
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
        m_app->shutdown();
    }
}