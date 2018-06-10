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

        // get window width and height
        inline int getWidth()  { return m_width; }
        inline int getHeight() { return m_height; }

    private:
        static void resizeEvent(GLFWwindow *window, int width, int height); 
        static void keyPressedEvent(GLFWwindow *window, int key, int scancode, int action, int mode);

    private:
        GLFWwindow *m_window;   // glfw window instance

        // window size
        unsigned m_width;
        unsigned m_height;
    };
}

#endif//_APP_H_