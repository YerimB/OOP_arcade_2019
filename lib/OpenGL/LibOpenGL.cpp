/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibOpenGL
*/

#include "LibOpenGL.hpp"

static LibOpenGL *lib = NULL;

LibOpenGL::LibOpenGL() :
_textMode(false), _gameMode(false)
{
    { // Set up Key mapping
        key_map[SDLK_a] = "a";
        key_map[SDLK_z] = "z";
        key_map[SDLK_e] = "e";
        key_map[SDLK_r] = "r";
        key_map[SDLK_t] = "t";
        key_map[SDLK_y] = "y";
        key_map[SDLK_LEFT] = "left";
        key_map[SDLK_RIGHT] = "right";
        key_map[SDLK_UP] = "up";
        key_map[SDLK_DOWN] = "down";
        key_map[SDLK_l] = "next";
        key_map[SDLK_k] = "prev";
    }
}

void LibOpenGL::enterTextMode(void)
{
    this->_textMode = true;
}

void LibOpenGL::drawText(const std::string &str, \
const Vector2<int> &position, const std::string &color)
{
    int idx = 0;

    for (; idx < str.length(); ++idx) {
        if (!this->_letter->setLetter(str[idx]))
            continue;
        if (str.compare(0, 5, "score") == 0) // Draw score differently
            this->_letter->setPosition(glm::vec3(
                static_cast<float>(-2 + (position.x / 30) + idx * 3),
                0.0,
                51.5
            ));
        else
            this->_letter->setPosition(glm::vec3(
                static_cast<float>(-2 + (position.x / 30) + idx * 3),
                0.0,
                static_cast<float>(position.y)
            ));
        this->_letter->draw(
            GL_TRIANGLES,
            this->_manager->getPerspectiveMatrix(),
            (*this->_camera)
        );
    }
    if (color == "yellow") {
        if (!this->_letter->setLetter('.'))
            return;
        this->_letter->setPosition(glm::vec3(
            static_cast<float>(-2 + (position.x / 30) + idx * 4),
            0.0,
            static_cast<float>(position.y)
        ));
        this->_letter->draw(
            GL_TRIANGLES,
            this->_manager->getPerspectiveMatrix(),
            (*this->_camera)
        );
    }
}

void LibOpenGL::Init(void)
{
    this->_manager = std::make_unique<GLManager>();
    this->_camera = std::make_unique<Camera>(
        glm::vec3(30.0, 50.0, 60.0),
        glm::vec3(270.0, 300.0, 0.0)
    );
    this->_manager->initWindow("openGL/SDL2", 1208, 720);
    this->_shader = std::make_shared<Shader>("./lib/OpenGL/shaders/vertex/vertex.glsl",
    "./lib/OpenGL/shaders/fragment/fragShader.glsl");
    this->_letter = std::make_shared<CubeChar>();
    this->_letter->setScalation(glm::vec3(3.0, 3.0, 3.0));
    this->_letter->setRotation(glm::vec3(0.0, 0.0, 0.0));
    this->_letter->setShader(*this->_shader, this->_manager->getPerspectiveMatrix());
    { // Set up alphabet object LMAO
        this->_letter->addLetter('0', std::make_shared<Texture>("lib/assets/textures/0.jpg"));
        this->_letter->addLetter('1', std::make_shared<Texture>("lib/assets/textures/1.jpg"));
        this->_letter->addLetter('2', std::make_shared<Texture>("lib/assets/textures/2.jpg"));
        this->_letter->addLetter('3', std::make_shared<Texture>("lib/assets/textures/3.jpg"));
        this->_letter->addLetter('4', std::make_shared<Texture>("lib/assets/textures/4.jpg"));
        this->_letter->addLetter('5', std::make_shared<Texture>("lib/assets/textures/5.jpg"));
        this->_letter->addLetter('6', std::make_shared<Texture>("lib/assets/textures/6.jpg"));
        this->_letter->addLetter('7', std::make_shared<Texture>("lib/assets/textures/7.jpg"));
        this->_letter->addLetter('8', std::make_shared<Texture>("lib/assets/textures/8.jpg"));
        this->_letter->addLetter('9', std::make_shared<Texture>("lib/assets/textures/9.jpg"));
        this->_letter->addLetter('a', std::make_shared<Texture>("lib/assets/textures/A.jpg"));
        this->_letter->addLetter('b', std::make_shared<Texture>("lib/assets/textures/B.jpg"));
        this->_letter->addLetter('c', std::make_shared<Texture>("lib/assets/textures/C.jpg"));
        this->_letter->addLetter('d', std::make_shared<Texture>("lib/assets/textures/D.jpg"));
        this->_letter->addLetter('e', std::make_shared<Texture>("lib/assets/textures/E.jpg"));
        this->_letter->addLetter('f', std::make_shared<Texture>("lib/assets/textures/F.jpg"));
        this->_letter->addLetter('g', std::make_shared<Texture>("lib/assets/textures/G.jpg"));
        this->_letter->addLetter('h', std::make_shared<Texture>("lib/assets/textures/H.jpg"));
        this->_letter->addLetter('i', std::make_shared<Texture>("lib/assets/textures/I.jpg"));
        this->_letter->addLetter('j', std::make_shared<Texture>("lib/assets/textures/J.jpg"));
        this->_letter->addLetter('k', std::make_shared<Texture>("lib/assets/textures/K.jpg"));
        this->_letter->addLetter('l', std::make_shared<Texture>("lib/assets/textures/L.jpg"));
        this->_letter->addLetter('m', std::make_shared<Texture>("lib/assets/textures/M.jpg"));
        this->_letter->addLetter('n', std::make_shared<Texture>("lib/assets/textures/N.jpg"));
        this->_letter->addLetter('o', std::make_shared<Texture>("lib/assets/textures/O.jpg"));
        this->_letter->addLetter('p', std::make_shared<Texture>("lib/assets/textures/P.jpg"));
        this->_letter->addLetter('q', std::make_shared<Texture>("lib/assets/textures/Q.jpg"));
        this->_letter->addLetter('r', std::make_shared<Texture>("lib/assets/textures/R.jpg"));
        this->_letter->addLetter('s', std::make_shared<Texture>("lib/assets/textures/S.jpg"));
        this->_letter->addLetter('t', std::make_shared<Texture>("lib/assets/textures/T.jpg"));
        this->_letter->addLetter('u', std::make_shared<Texture>("lib/assets/textures/U.jpg"));
        this->_letter->addLetter('v', std::make_shared<Texture>("lib/assets/textures/V.jpg"));
        this->_letter->addLetter('w', std::make_shared<Texture>("lib/assets/textures/W.jpg"));
        this->_letter->addLetter('x', std::make_shared<Texture>("lib/assets/textures/X.jpg"));
        this->_letter->addLetter('y', std::make_shared<Texture>("lib/assets/textures/Y.jpg"));
        this->_letter->addLetter('z', std::make_shared<Texture>("lib/assets/textures/Z.jpg"));
        this->_letter->addLetter('.', std::make_shared<Texture>("lib/assets/textures/red.jpg"));
    }
    this->_open = true;
}

void LibOpenGL::clearWindow(void)
{
    if (this->_gameMode) {
        this->_camera->setPosition(glm::vec3(30.0, 50.0, 60.0));
        this->_camera->setRotation(glm::vec3(270.0, 300.0, 0.0));
    } else {
        this->_camera->setPosition(glm::vec3(50.0, 90.0, 60.0));
        this->_camera->setRotation(glm::vec3(270.0, 280.0, 0.0));
    }
    this->_camera->updateView();
    this->_manager->clearWindow(0.3, 0.3, 0.7);
    this->_letter->rotate(Object::ROT_X, 1.0);
    this->_gameMode = false;
}

void LibOpenGL::drawRectangle(const Rectangle<int> &rect, const std::string &color)
{
    float rotation = 0.0f;
    std::string texture_name;
    float pos_x = rect.p1;
    float pos_z = rect.p2;

    this->_gameMode = true;
    if (color.find(":") == std::string::npos) {
        this->_objects["wall.jpg"]->setPosition(glm::vec3(pos_x / 2, -2.0, pos_z));
        this->_objects["wall.jpg"]->draw(
            GL_TRIANGLES,
            this->_manager->getPerspectiveMatrix(),
            (*this->_camera)
        );
        return;
    }
    texture_name = color.substr(color.find(":") + 1, color.find("°") - color.find(":") - 1);
    rotation = std::stof(color.substr(color.find("°") + 2, color.length()));
    rotation += (rotation == 90.0 || rotation == 270.0) ? 180.0 : 0.0;
    this->_objects[texture_name]->setPosition(glm::vec3(pos_x / 2, 0.0, pos_z));
    this->_objects[texture_name]->setRotation(glm::vec3(0.0, rotation, 0.0));
    this->_objects[texture_name]->draw(
        GL_TRIANGLES,
        this->_manager->getPerspectiveMatrix(),
        (*this->_camera)
    );
}

const std::string LibOpenGL::handleEvent(void)
{
    std::string cmd;

    if (this->_textMode) {
        cmd = this->_manager->getInputChar(this->_input);
        if (cmd == "done") {
            this->_textMode = false;
            return ("text: '" + this->_input + "'");
        }
    } else
        cmd = this->_manager->handleEvents(this->key_map, *this->_camera);
    if (cmd == "exit")
        this->close();
    return (cmd);
}

void LibOpenGL::loadTextures(std::vector<std::string> textures)
{
    this->_objects["wall.jpg"] = std::make_shared<Cube>();
    this->_objects["wall.jpg"]->setScalation(glm::vec3(2.0, 2.0, 2.0));
    this->_objects["wall.jpg"]->setShader(*this->_shader, this->_manager->getPerspectiveMatrix());
    this->_objects["wall.jpg"]->setTexture(std::make_shared<Texture>("lib/assets/textures/wall.jpg"));
    for (std::string name : textures) {
        this->_objects[name] = std::make_shared<Cube>();
        if (name == "bricks.png")
            this->_objects[name]->setScalation(glm::vec3(2.0, 2.0, 2.0));
        else if (name == "pacmiam.png")
            this->_objects[name]->setScalation(glm::vec3(0.7, 0.7, 0.7));
        else
            this->_objects[name]->setScalation(glm::vec3(1.6, 1.6, 1.6));
        this->_objects[name]->setShader(*this->_shader, this->_manager->getPerspectiveMatrix());
        this->_objects[name]->setTexture(std::make_shared<Texture>("lib/assets/textures/" + name));
    }
}

void LibOpenGL::drawWindow(void)
{
    if (this->_textMode)
        this->drawText(this->_input, Vector2<int>(600, 30), "");
    SDL_GL_SwapWindow(this->_manager->getWindow());
}

void LibOpenGL::close(void)
{
    this->_objects.clear();
    this->_camera.reset();
    this->_shader.reset();
    this->_letter.reset();
    this->_manager.reset();
    this->_open = false;
}

const bool LibOpenGL::isOpen(void) const
{
    return (this->_open);
}

LibOpenGL::~LibOpenGL() {}

extern "C"
{
    __attribute__((constructor))
    void ctor ()
    {
        lib = new LibOpenGL;
    }

    __attribute__((destructor))
    void dtor ()
    {
        delete (lib);
    }

    LibOpenGL *entryPoint()
    {
        return lib;
    }
}