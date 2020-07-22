/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <SFML/Graphics/Color.hpp>

struct Color {
    Color(const int &_r, const int &_g, const int &_b, const int &_a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    };

    Color(const sf::Color &color)
    {
        r = color.r;
        g = color.g;
        b = color.b;
        a = color.a;
    }

    int r;
    int b;
    int g;
    int a;
};

#endif /* !COLOR_HPP_ */
