/*
** EPITECH PROJECT, 2020
** test2
** File description:
** Manager
*/

#include "GLManager.hpp"

/* -------------- INITIALIZATION -------------- */

GLManager::GLManager()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->_evt = std::make_unique<SDL_Event>(SDL_Event());
}

void GLManager::initWindow(const std::string &name, const int &wid, const int &hei)
{
    int windowPosX = 0;
    int windowPosY = 0;

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); // Sets major version of openGL to use
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3); // Sets minor version of openGL to use
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // Sets profile to core
    #ifdef __APPLE__
        std::cout << "\t[APPLE DETECTED]" << std::endl;
    #endif

    this->_window = SDL_CreateWindow(
        name.c_str(),
        windowPosX, windowPosY,
        wid, hei,
        SDL_WINDOW_OPENGL
    );
    if (!this->_window) {
        std::cerr << "\tFailed to create SDL window" << std::endl;
        SDL_Quit();
        std::exit(84);
    }
    this->_context = SDL_GL_CreateContext(&(*this->_window)); // Links the context to the window
    this->setPerpectiveMatrix(45.0f, float(wid) / float(hei), 0.1f, 100.0f);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, wid, hei); // Setting the view
}

void GLManager::setPerpectiveMatrix(const float &angle, \
const float &ratio, const float &nearPlane, const float &farPlane)
{
    this->_perspective = glm::perspective(glm::radians(angle), ratio, nearPlane, farPlane);
}

/* -------------- GRAPHICAL -------------- */

void GLManager::clearWindow(const GLclampf &r, \
const GLclampf &g, const GLclampf &b, const GLclampf &a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/* -------------- EVENTS -------------- */

const bool GLManager::handleKeyDown(const SDL_Keysym &key, Camera &cam)
{
    switch (key.sym) {
        // case SDLK_ESCAPE: return (false);
        // case SDLK_z: cam.move(cam.FRONT, 30.0f); break;
        // case SDLK_q: cam.move(cam.LEFT, 30.0f); break;
        // case SDLK_s: cam.move(cam.BACK, 30.0f); break;
        // case SDLK_d: cam.move(cam.RIGHT, 30.0f); break;
        // case SDLK_u: cam.rotate(cam.ROT_Y, 80.0f); break;
        // case SDLK_h: cam.rotate(cam.ROT_X, -80.0f); break;
        // case SDLK_j: cam.rotate(cam.ROT_Y, -80.0f); break;
        // case SDLK_k: cam.rotate(cam.ROT_X, 80.0f); break;
        default: break;
    }
    return (true);
}

void GLManager::handleKeyUp(const SDL_Keysym &key, Camera &cam)
{
    switch (key.sym) {
        // case SDLK_z: cam.move(cam.FRONT, 0.0f); break;
        // case SDLK_q: cam.move(cam.LEFT, 0.0f); break;
        // case SDLK_s: cam.move(cam.BACK, 0.0f); break;
        // case SDLK_d: cam.move(cam.RIGHT, 0.0f); break;
        // case SDLK_u: cam.rotate(cam.ROT_Y, 0.0f); break;
        // case SDLK_h: cam.rotate(cam.ROT_X, 0.0f); break;
        // case SDLK_j: cam.rotate(cam.ROT_Y, 0.0f); break;
        // case SDLK_k: cam.rotate(cam.ROT_X, 0.0f); break;
        default: break;
    }
}

const std::string GLManager::handleEvents(const std::map<SDL_Keycode, std::string> &keymap, Camera &cam)
{
    while (SDL_PollEvent(this->_evt.get())) {
        switch (this->_evt->type) {
            case SDL_KEYDOWN:
                if (keymap.find(this->_evt->key.keysym.sym) != keymap.end())
                    return (keymap.find(this->_evt->key.keysym.sym)->second);
                break;
            case SDL_QUIT: return ("exit");
            default: break;
        }
    }
    return ("");
}

const std::string GLManager::getInputChar(std::string &toFill)
{
    while (SDL_PollEvent(this->_evt.get())) {
        if (this->_evt->type == SDL_KEYDOWN) {
            if (this->_evt->key.keysym.sym > 96 && \
            this->_evt->key.keysym.sym < 123 && toFill.length() < 6)
                toFill += this->_evt->key.keysym.sym;
            else if (this->_evt->key.keysym.sym == SDLK_SPACE && toFill.length())
                return ("done");
            if (this->_evt->key.keysym.sym == SDLK_BACKSPACE && !toFill.empty())
                toFill.pop_back();
        } else if (this->_evt->type == SDL_QUIT)
            return ("exit");
    }
    return ("");
}

GLManager::~GLManager()
{
    if (this->_window)
        SDL_DestroyWindow(this->_window);
    SDL_Quit();
}