//
// Created by Yuno on 11/03/2020.
//

#include "Ghost.hpp"

Vector2<int> Ghost::getPosition()
{
    return _pos;
}

void Ghost::setPos(Vector2<int> pos)
{
    _pos = pos;
}

std::string Ghost::getColor()
{
    return _isPackManUber ? "blue:dead_ghost.png°0" : "red:ghost.png°0";
}

Vector2<int> Ghost::getDir()
{
    return _dir;
}

void Ghost::setDir(Vector2<int> dir)
{
    _dir = dir;
}

bool Ghost::getState()
{
    return _isPackManUber;
}

void Ghost::setUber(bool state)
{
    _isPackManUber = state;
}

std::string Ghost::getName()
{
    return "ghost";
}

void Ghost::move()
{
    _pos.x += _dir.x;
    _pos.y += _dir.y;
}