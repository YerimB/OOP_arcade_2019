/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CubeChar
*/

#include "CubeChar.hpp"

CubeChar::CubeChar(const glm::vec3 &position, \
const glm::vec3 &rotation, const glm::vec3 &scalation) :
Cube::Cube(position, rotation, scalation) {}

void CubeChar::addLetter(const char &let, const std::shared_ptr<Texture> &tex)
{
    this->_textures.insert({let, tex});
}

const bool CubeChar::setLetter(const char &let)
{
    for (auto &elem : this->_textures)
        if (elem.first == let || \
        elem.first == let - 32 || elem.first == let + 32) {
            this->setTexture(elem.second);
            return (true);
        }
    return (false);
}