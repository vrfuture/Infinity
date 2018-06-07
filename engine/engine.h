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

        void init();
        // Main loop function
        void mainloop();

        void update();
        void render();
        void swap();

        void shutdown();

        private:
        Framework::App *m_app;
    };
}

#endif//_ENGINE_H_