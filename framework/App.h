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
        static void mousePressEvent(GLFWwindow*, int button, int action, int mods);
        static void mouseMoveEvent(GLFWwindow* window, double x, double y);
        static void mouseWhellEvent(GLFWwindow* window, double x, double y);

    private:
        GLFWwindow *m_window;   // glfw window instance

        // window size
        int m_width;
        int m_height;

        // mouse cursor position
        static int m_last_cursor_position_x, m_cursor_position_x;
        static int m_last_cursor_position_y, m_cursor_position_y;

        // mouse button state
        static int m_mouse_button_state[4];
    };
}

#endif//_APP_H_