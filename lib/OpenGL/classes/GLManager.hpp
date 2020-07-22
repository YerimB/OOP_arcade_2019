/*
** EPITECH PROJECT, 2020
** test2
** File description:
** Manager
*/

#ifndef GLMANAGER_HPP_
#define GLMANAGER_HPP_

#ifndef GL_SILENCE_DEPRECATION
#define GL_SILENCE_DEPRECATION
#endif

#include "Camera.hpp"

// GL & SDL2 includes

#ifdef __linux__
    #include <GL/gl.h>
    #include <GLES3/gl3.h>
#else
    #include <OpenGL/gl3.h>
#endif

#include <SDL2/SDL.h>

// C++ Includes
#include <iostream>
#include <memory>

class GLManager {
    public: // General
        GLManager();
        ~GLManager();
        inline SDL_Window *getWindow(void) const { return (this->_window); };
        inline const glm::mat4 &getPerspectiveMatrix(void) const { return (this->_perspective); };

    public: // Initialize
        void initWindow(const std::string &name, const int &wid = 800, const int &len = 600);
        void setPerpectiveMatrix(const float &angle, \
        const float &ratio, const float &nearPlane, const float &farPlane);

    public:
        void clearWindow(const GLclampf &r = 0.0f, const GLclampf &g = 0.0f, \
                        const GLclampf &b = 0.0f, const GLclampf &a = 1.0f);

    public: // Events
        const std::string handleEvents(const std::map<SDL_Keycode, std::string> &keymap, Camera &cam);
        const bool handleKeyDown(const SDL_Keysym &key, Camera &cam);
        void handleKeyUp(const SDL_Keysym &key, Camera &cam);
        const std::string getInputChar(std::string &toFill);

    private:
        SDL_Window *_window;
        SDL_GLContext _context;
        std::unique_ptr<SDL_Event> _evt;
        glm::mat4 _perspective;
};

#endif /* !GLMANAGER_HPP_ */