/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#ifndef TEK2_SNAKE_HPP
#define TEK2_SNAKE_HPP

#include "IEntity.hpp"

class Snake : public IEntity {
    public:
        Snake(const Vector2<int> &direction, const Vector2<int> &position);
        const std::string getName(void) const final;
        const std::string getColor(void) const final;
        Vector2<int> getPos();
        void updatePosition(const Vector2<int> &direction);
        void unsetHead();

    private:
        bool _isHead;
        Vector2<int> _dir;
        Vector2<int> _pos;
};

#endif //TEK2_SNAKE_HPP