//
// Created by Yuno on 11/03/2020.
//

#include "Wall.hpp"

Vector2<int> Wall::getPosition()
{
    return _pos;
}

std::string Wall::getColor()
{
    return "black:bricks.png°0";
}

std::string Wall::getName()
{
    return "wall";
}