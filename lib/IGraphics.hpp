/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphics
*/

#ifndef IGRAPHICS_HPP_
#define IGRAPHICS_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <vector>
#include <iostream>
#include <curses.h>
#include <memory>

#include "Templates/Color.hpp"
#include "Templates/Vector.hpp"
#include "Templates/Rectangle.hpp"

#include <unistd.h>

class IGraphics {
    public:
        ~IGraphics() = default;

    public:
        virtual void Init() = 0;
        virtual void drawRectangle(const Rectangle<int> &rect, const std::string &color) = 0;
        virtual void drawWindow(void) = 0;
        virtual const std::string handleEvent(void) = 0;
        virtual void drawText(const std::string &text, const Vector2<int> &position, const std::string &color) = 0;
        virtual void clearWindow(void) = 0;
        virtual void enterTextMode() = 0;
        virtual void loadTextures(std::vector<std::string>) = 0;
        virtual void close() = 0;
        virtual const bool isOpen() const = 0;
};

#endif /* !IGRAPHICS_HPP_ */
