#ifndef _ENGINE_H_
#define _ENGINE_H_

namespace Framework{
    class App;
}

namespace Infinity{

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

    struct EngineGlobals {
        Engine *engine;
        Framework::App *app;

        EngineGlobals(){
            engine = nullptr;
            app = nullptr;
        }
    };

    extern EngineGlobals engine;
}

#endif//_ENGINE_H_