/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#include "Snake.hpp"

Snake::Snake(const Vector2<int> &dir, const Vector2<int> &pos):
_isHead(true), _dir(dir), _pos(pos) {}

const std::string Snake::getName(void) const
{
    return ("Snake");
}

const std::string Snake::getColor(void) const
{
    if (this->_isHead) {
        if (_dir.x == 0 && _dir.y == 1) return "green:frolian.png°180";
        if (_dir.x == 0 && _dir.y == -1) return "green:frolian.png°270";
        if (_dir.x == 1 && _dir.y == 0) return "green:frolian.png°90";
        if (_dir.x == -1 && _dir.y == 0) return "green:frolian.png°0";
    }
    return "red:pokeball.png°0";
}

Vector2<int> Snake::getPos()
{
    return (this->_pos);
}

void Snake::unsetHead()
{
    this->_isHead = false;
}