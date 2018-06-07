#ifndef _APP_H_
#define _APP_H_

struct GLFWwindow;

namespace Framework{
    class App
    {
    public:
        App();
        App(unsigned width, unsigned height);
        virtual ~App();

        bool shouldAppClose();

        int init();

        void update();
        void render();
        void swap();

        void shutdown();

    private:
        GLFWwindow *m_window;   // glfw window instance

        // window size
        unsigned m_width;
        unsigned m_height;
    };
}

#endif//_APP_H_