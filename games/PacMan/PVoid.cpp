//
// Created by Yuno on 12/03/2020.
//

#include "PVoid.hpp"

std::string PVoid::getColor()
{
    return "white";
}

std::string PVoid::getName()
{
    return "void";
}

Vector2<int> PVoid::getPosition(){
    return _pos;
}