//
// Created by Yuno on 02/03/2020.
//

#include "LibSFML.hpp"

static LibSFML *lib = NULL;

LibSFML::LibSFML()
{
    this->_textMode = false;

    this->_font = std::make_unique<sf::Font>();
    this->_text = std::make_unique<sf::Text>();
    this->_font->loadFromFile("lib/assets/arial.ttf");
    key_map[sf::Keyboard::A] = "a";
    key_map[sf::Keyboard::Z] = "z";
    key_map[sf::Keyboard::E] = "e";
    key_map[sf::Keyboard::R] = "r";
    key_map[sf::Keyboard::T] = "t";
    key_map[sf::Keyboard::Y] = "y";
    key_map[sf::Keyboard::Left] = "left";
    key_map[sf::Keyboard::Right] = "right";
    key_map[sf::Keyboard::Up] = "up";
    key_map[sf::Keyboard::Down] = "down";
    key_map[sf::Keyboard::L] = "next";
    key_map[sf::Keyboard::K] = "prev";
}

void LibSFML::Init()
{
    this->_window = std::make_unique<sf::RenderWindow>();
    this->_window->create(sf::VideoMode(800, 600), "SFML");
    this->_window->setFramerateLimit(60);
}

sf::Color LibSFML::getColor(std::string color) const
{
    if (color == "black") return sf::Color::Black;
    if (color == "red") return sf::Color::Red;
    if (color == "green") return sf::Color::Green;
    if (color == "yellow") return sf::Color::Yellow;
    if (color == "blue") return sf::Color::Blue;
    if (color == "magenta") return sf::Color::Magenta;
    if (color == "cyan") return sf::Color::Cyan;
    if (color == "white") return sf::Color::White;
    return sf::Color::Black;
}

void LibSFML::enterTextMode()
{
    this->_textMode = true;
}

void LibSFML::drawText(const std::string &str, const Vector2<int> &position, const std::string &color)
{
    sf::Color c = getColor(color);

    this->_text->setFont(*this->_font);
    this->_text->setString(str);
    this->_text->setCharacterSize(40);
    this->_text->setStyle(sf::Text::Bold);
    this->_text->setFillColor(c);
    this->_text->setPosition(sf::Vector2f(position.x * 4, position.y * 10));
    this->_window->draw(*this->_text);
}

void LibSFML::clearWindow()
{
    this->_window->clear(sf::Color::Black);
}

void LibSFML::drawRectangle(const Rectangle<int> &rect, const std::string &color)
{
    std::string sprite_name;
    sf::RectangleShape rectShape(sf::Vector2f(rect.p3 * 8, rect.p4 * 5));

    rectShape.setPosition(sf::Vector2f(rect.p1 * 4, rect.p2 * 10));
    if (color.find(":") < color.length()) {
        sprite_name = color.substr(color.find(":") + 1, color.length());
        rectShape.setTexture(textures_map[sprite_name.substr(0, sprite_name.find("°"))].get());
        rectShape.setOrigin(rectShape.getSize() / 2.f);
        rectShape.setRotation(std::stoi(sprite_name.substr(sprite_name.find("°") + 2, sprite_name.length())));
    } else
        rectShape.setFillColor(getColor(color));
    this->_window->draw(rectShape);
}

const std::string LibSFML::handleEvent()
{
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->_window->close();
            return "exit";
        }
        if (_textMode)
        {
            if (event.type == sf::Event::TextEntered) {
                std::cout << event.text.unicode << std::endl;
                if (event.text.unicode < 128)
                {
                    if ((static_cast<char>(event.text.unicode) == ' '
                    || static_cast<char>(event.text.unicode) == '\n')
                    && (_str.length() != 0)) {
                        this->_textMode = false;
                        return "text: '" + _str + "'";
                    } else if (_str.length() < 6) {
                        _str += static_cast<char>(event.text.unicode);
                    }
                }
                if (_str == "e") _str = "";
            }
        }
        else if (event.type == sf::Event::KeyPressed)
            for (auto it = key_map.begin(); it != key_map.end(); it++)
                if (event.key.code == it->first)
                    return it->second;
    }
    return "";
}

void LibSFML::loadTextures(std::vector<std::string> textures)
{
    for (std::string textureName: textures) {
        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>(); // [???]
        texture->loadFromFile("lib/assets/textures/" + textureName);
        textures_map[textureName] = texture;
    }
}

void LibSFML::drawWindow()
{
    if (_window->isOpen()) {
        if (this->_textMode)
            drawText(_str, Vector2<int>(70, 30), "white");
        this->_window->display();
    } else
        throw "Windows is closed";
}

void LibSFML::close()
{
    if (this->_window->isOpen()) {
        this->_window->close();
        this->textures_map.clear();
        this->_window.reset();
    }
}

const bool LibSFML::isOpen() const
{
    return this->_window->isOpen();
}

extern "C"
{
    __attribute__((constructor))
    void ctor ()
    {
        lib = new LibSFML;
    }

    __attribute__((destructor))
    void dtor ()
    {
        // delete (lib);
    }

    LibSFML *entryPoint()
    {
        return lib;
    }

    void draw_square(const Rectangle<int> &rect, const std::string &color)
    {
        lib->drawRectangle(rect, color);
        lib->drawText("toto", {100, 100}, "Red");
    }

    void draw()
    {
        if (!lib)
            std::cout << "hmm lil problem" << std::endl;
        lib->drawWindow();
    }
}
