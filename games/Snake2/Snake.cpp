/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#include "Snake.hpp"

Snake::Snake(const Vector2<int> &startPos) :
_headPos(startPos.x, startPos.y) {}

void Snake::grow(void)
{
    this->_bodyPos.push_back(Vector2<int>(-1, -1));
}

void Snake::move(const Vector2<int> &d)
{
    if (this->_bodyPos.size() != 0) {
        std::cout << "__________________loop:size(" << this->_bodyPos.size() << ")______________" << std::endl;
        for (int idx = this->_bodyPos.size() - 1; idx > 0; --idx) {
            std::cout << "copy pos[" << idx << "] to pos[" << idx - 1 << "]" << std::endl;
            this->_bodyPos[idx - 1] = this->_bodyPos[idx];
            std::cout << "set." << std::endl;
        }
        std::cout << "toto" << std::endl;
        this->_bodyPos.begin()->SetPosition(_headPos.x, _headPos.y);
    }
    this->_headPos.SetPosition(this->_headPos.x + d.x, this->_headPos.y + d.y);
}

const Vector2<int> &Snake::getHeadPosition(void)
{
    return (this->_headPos);
}

const std::vector<Vector2<int> > &Snake::getBodyPositions(void)
{
    return (this->_bodyPos);
}

const std::string Snake::getColor(const std::string &t, const std::string &d)
{
    if (t == "head") {
        if (d == "up") return ("green:frolian.png°180");
        else if (d == "down") return ("green:frolian.png°270");
        else if (d == "right") return ("green:frolian.png°90");
        else if (d == "left") return ("green:frolian.png°0");
    }
    return ("red:pokeball.png°0");
}