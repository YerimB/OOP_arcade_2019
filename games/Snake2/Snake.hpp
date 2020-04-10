/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../../lib/Templates/Vector.hpp"
#include <iostream>
#include <vector>

class Snake {
    public:
        Snake(const Vector2<int> &startPos = Vector2<int>(0, 0));
        ~Snake() = default;
    
    public:
        void grow(void);
        void move(const Vector2<int> &direction);
        inline const uint getLength(void) const { return (this->_bodyPos.size() + 1); };
        const Vector2<int> &getHeadPosition(void);
        const std::vector<Vector2<int> > &getBodyPositions(void);
        const std::string getColor(const std::string &type = "body", const std::string &d = "up");

    private:
        Vector2<int> _headPos;
        std::vector<Vector2<int> > _bodyPos;
};

#endif /* !SNAKE_HPP_ */
