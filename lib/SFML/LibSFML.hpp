/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibSFML
*/

#ifndef TEK2_LIBSFML_HPP
#define TEK2_LIBSFML_HPP

#include "../IGraphics.hpp"
#include <map>

class LibSFML : public IGraphics {
    public:
        LibSFML();
        ~LibSFML();

    public:
        void Init();
        void drawRectangle(const Rectangle<int> &rect, const std::string &color) final;
        void drawWindow() final;
        const std::string handleEvent() final;
        void loadTextures(std::vector<std::string>) final;
        void enterTextMode();
        sf::Color getColor(std::string) const;
        void drawText(const std::string &str, const Vector2<int> &position, const std::string &color) final;
        void clearWindow() final;
        void close() final;
        const bool isOpen() const final;

    private:
        std::unique_ptr<sf::RenderWindow> _window;
        std::unique_ptr<sf::Text> _text;
        std::unique_ptr<sf::Font> _font;
        std::map<sf::Keyboard::Key, std::string> key_map;
        std::map<std::string, std::shared_ptr<sf::Texture> > textures_map;
        std::string _str;
        bool _textMode;
};


#endif //TEK2_LIBSFML_HPP
