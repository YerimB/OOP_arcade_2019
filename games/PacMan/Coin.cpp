/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Coin
*/

#include "Coin.hpp"

std::string PCoin::getColor()
{
    return "magenta:pacmiam.png°0";
}

Vector2<int> PCoin::getPosition()
{
    return _pos;
}

std::string PCoin::getName()
{
    return "coin";
}
