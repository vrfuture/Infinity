#include "App.h"
#include "engine/engine.h"
#include "world/World.h"
#include "players/PlayerOrbit.h"

#ifdef WIN32
    #include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

#include <iostream>

namespace Infinity{

    // mouse cursor position
    int App::m_last_cursor_position_x = 0, App::m_cursor_position_x = 0;
    int App::m_last_cursor_position_y = 0, App::m_cursor_position_y = 0;

    // mouse button state
    int App::m_mouse_button_state[4];
    // mouse rotation sensetive
    const float c_mouseSensitive = 0.1f;

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

        // glfw multiple sample
        glfwWindowHint(GLFW_SAMPLES, 4);

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

        //glEnable(GL_DEPTH_TEST);
        
        // register keyboard event
        glfwSetKeyCallback(m_window, keyPressedEvent);
        // register window resize event
        glfwSetWindowSizeCallback(m_window, resizeEvent);

        // set mouse press and move event function callback
        glfwSetMouseButtonCallback(m_window, mousePressEvent);
	    glfwSetCursorPosCallback(m_window, mouseMoveEvent);

        // mouse whell event
        glfwSetScrollCallback(m_window, mouseWhellEvent);
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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
        else if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        {
            // enable multisample
            glEnable(GL_MULTISAMPLE);
        }
        else if (key == GLFW_KEY_E && action == GLFW_PRESS)
        {
            // disable multisample
            glDisable(GL_MULTISAMPLE);
        }
    }

    void App::mousePressEvent(GLFWwindow*, int button, int action, int mods)
    {
        if(action == GLFW_PRESS)
        {
            switch(button)
            {
                case GLFW_MOUSE_BUTTON_LEFT:
                    // record current mouse position
                    m_last_cursor_position_x = m_cursor_position_x;
                    m_last_cursor_position_y = m_cursor_position_y;
                    m_mouse_button_state[GLFW_MOUSE_BUTTON_LEFT] = 1;
                    break;
                default:
                    return;
            }
        }
        else if(action == GLFW_RELEASE)
        {
            switch(button)
            {
                case GLFW_MOUSE_BUTTON_LEFT:
                    m_mouse_button_state[GLFW_MOUSE_BUTTON_LEFT] = 0;
                    break;
                default:
                    return;
            }
        }
    }

    void App::mouseMoveEvent(GLFWwindow* window, double x, double y)
    {
        m_cursor_position_x = x;
        m_cursor_position_y = y;
        //std::cout <<x << ", " <<y<<std::endl;
        if(m_mouse_button_state[GLFW_MOUSE_BUTTON_LEFT])
        {
            PlayerOrbit *_player = static_cast<PlayerOrbit*>(engine.world->getPlayer());
            if(_player)
            {
                double _deltaX = x - m_last_cursor_position_x;
                double _deltaY = y - m_last_cursor_position_y;

                float _alpha = _player->getAlpha() + (float)_deltaY * c_mouseSensitive;
                float _theta = _player->getTheta() + (float)_deltaX * c_mouseSensitive;
                _player->setAlpha(_alpha);
                _player->setTheta(_theta);

                m_last_cursor_position_x = m_cursor_position_x;
                m_last_cursor_position_y = m_cursor_position_y;
            }
        }
    }

    void App::mouseWhellEvent(GLFWwindow* window, double x, double y)
    {
        PlayerOrbit *_player = static_cast<PlayerOrbit*>(engine.world->getPlayer());
        if(_player)
        {
            float _radius = _player->getRadius() + y * c_mouseSensitive;
            _player->setRadius(_radius);
        }
    }
}