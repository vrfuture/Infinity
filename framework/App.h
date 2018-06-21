#ifndef _APP_H_
#define _APP_H_

struct GLFWwindow;

namespace Infinity{
    class App
    {
    public:
        App();
        App(unsigned width, unsigned height);
        virtual ~App();

        bool shouldAppClose();

        int init();
        inline void setWidth(int width) { m_width = width; }
        inline void setHeight(int height) { m_height = height; }

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
        int m_width;
        int m_height;
    };
}

#endif//_APP_H_