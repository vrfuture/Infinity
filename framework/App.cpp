#include "App.h"
#include "engine/engine.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

#include <iostream>

namespace Infinity{

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

        // configure glfw3 based window hint
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        // Create a windowed mode window and its OpenGL context
        m_window = glfwCreateWindow(m_width, m_height, "Infinity-engine", NULL, NULL);
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
        
        // register keyboard event
        glfwSetKeyCallback(m_window, keyPressedEvent);
        // register window resize event
        glfwSetWindowSizeCallback(m_window, resizeEvent);
    }

    bool App::shouldAppClose()
    {
        return glfwWindowShouldClose(m_window);
    }

    void App::update()
    {
        // firstly, poll for and process events
        glfwPollEvents();
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
    }

    void App::shutdown()
    {
        glfwTerminate();
    }

    void App::resizeEvent( GLFWwindow *window, int width, int height)
    {
        // adjust window size according to resize callback
        engine.app->setWidth(width);
        engine.app->setHeight(height);
    }

    void App::keyPressedEvent(GLFWwindow* window, int key, int scancode, int action, int mode)
    {
        if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
    }
}