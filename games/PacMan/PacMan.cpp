//
// Created by Yuno on 11/03/2020.
//

#include "PacMan.hpp"

Vector2<int> PacMan::getPosition()
{
    return _pos;
}

std::string PacMan::getColor()
{
    if (_dir.x == 0 && _dir.y == 1) return "yellow:pac.png°90"    ;
    if (_dir.x == 0 && _dir.y == -1) return "yellow:pac.png°270";
    if (_dir.x == 1 && _dir.y == 0) return "yellow:pac.png°0";
    if (_dir.x == -1 && _dir.y == 0) return "yellow:pac.png°180";
    return "";
}

std::string PacMan::getName()
{
    return "pacman";
}

Vector2<int> PacMan::getDir()
{
    return _dir;
}

void PacMan::setPos(Vector2<int> pos)
{
    _pos = pos;
}

void PacMan::move()
{
    _pos.x += _dir.x;
    _pos.y += _dir.y;
}

void PacMan::setDir(Vector2<int> dir)
{
    _dir = dir;
}