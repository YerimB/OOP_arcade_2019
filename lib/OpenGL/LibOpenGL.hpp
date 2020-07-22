/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibOpenGL
*/

#ifndef LIBOPENGL_HPP_
#define LIBOPENGL_HPP_

#include "../IGraphics.hpp"
#include "classes/GLManager.hpp"
#include "classes/CubeChar.hpp"
#include "../../core/Exceptions/ArcadeException.hpp"

class LibOpenGL : public IGraphics {
    public:
        LibOpenGL();
        ~LibOpenGL();

    public:
        void Init();
        void drawRectangle(const Rectangle<int> &rect, const std::string &color) final;
        void drawWindow() final;
        const std::string handleEvent() final;
        void loadTextures(std::vector<std::string>) final;
        sf::Color getColor(std::string) const;
        void enterTextMode(void);
        void drawText(const std::string &str, const Vector2<int> &position, const std::string &color) final;
        void clearWindow() final;
        void close() final;
        const bool isOpen() const final;

    private:
        std::unique_ptr<GLManager> _manager = nullptr;
        std::unique_ptr<Camera> _camera = nullptr;
        std::shared_ptr<Shader> _shader = nullptr;
        std::map<std::string, std::shared_ptr<Object> > _objects;
        std::shared_ptr<CubeChar> _letter = nullptr;
        std::map<SDL_Keycode, std::string> key_map;
        bool _open;
        bool _textMode;
        bool _gameMode;
        std::string _input;
};

#endif /* !LIBOPENGL_HPP_ */
