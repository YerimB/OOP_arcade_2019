//
// Created by Yuno on 05/03/2020.
//

#include "Snake.hpp"

Snake::Snake(Vector2<int> dir, Vector2<int> pos): _isHead(true), _dir(dir), _pos(pos)
{
}

Vector2<int> Snake::getPos()
{
    return this->_pos;
}

std::string Snake::getName()
{
    return "Snake";
}

void Snake::unsetHead()
{
    _isHead = false;
}

std::string Snake::getColor() {
    if (_isHead) {
        if (_dir.x == 0 && _dir.y == 1) return "green:frolian.png°180";
        if (_dir.x == 0 && _dir.y == -1) return "green:frolian.png°270";
        if (_dir.x == 1 && _dir.y == 0) return "green:frolian.png°90";
        if (_dir.x == -1 && _dir.y == 0) return "green:frolian.png°0";
    }
    return "red:pokeball.png°0";
}