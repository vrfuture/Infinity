#include "App.h"
#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

#include <iostream>

namespace Framework{

    App::App() : m_width(960), m_height(600)
    {

    } 

    App::App(unsigned width, unsigned height)
    {
        m_width  = width;
        m_height = height;
    }

    App::~App()
    {

    }

    int App::init()
    {
        // Initialize the library
        if(!glfwInit())
        {
            return -1;
        }
        // Create a windowed mode window and its OpenGL context
        m_window = glfwCreateWindow(m_width, m_height, "Infinity-Engine", NULL, NULL);
        if (!m_window)
        {
            glfwTerminate();
            return -1;
        }

        // Make the window's context current
        glfwMakeContextCurrent(m_window);
        #ifdef WIN32
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cout << "Failed to initialize GLAD" << std::endl;
                return -1;
            }
        #endif
    }

    bool App::shouldAppClose()
    {
        return glfwWindowShouldClose(m_window);
    }

    void App::update()
    {

    }

    void App::render()
    {
         // Render here
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void App::swap()
    {
        // Swap front and back buffers
        glfwSwapBuffers(m_window);

        // Poll for and process events
        glfwPollEvents();
    }

    void App::shutdown()
    {
        glfwTerminate();
    }
}