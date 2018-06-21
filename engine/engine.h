#ifndef _ENGINE_H_
#define _ENGINE_H_

namespace Infinity{
    
    // class forward declaration
    class App;
    class Render;
    class RenderManager;
    
    class Engine
    {
    public:
        Engine();
        virtual ~Engine();

        static void init();
        // Main loop function
        void mainloop();

        void update();
        void render();
        void swap();

        void shutdown();
    };

    // engine initialization preocess
    void initEngine();

    // engine destory engine
    void shutdownEngine();

    // Global variable definitions here =================================================
    struct EngineGlobals {
        Engine *engine;
        App *app;
        Render *render;
        RenderManager *renderManager;

        EngineGlobals(){
            engine = nullptr;
            app    = nullptr;
            render = nullptr;
            renderManager = nullptr;
        }
    };

    extern EngineGlobals engine;
}

#endif//_ENGINE_H_