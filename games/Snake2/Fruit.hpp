/*
** EPITECH PROJECT, 2020
** games
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include "../../lib/Templates/Vector.hpp"
#include <iostream>
#include <ctime>
#include <vector>

class Fruit {
    public:
        Fruit(std::vector<Vector2<int> > &freePos, const uint &maxFruits = 4);
        ~Fruit() = default;
    
    public:
        void getConsumed(const Vector2<int> &position);
        void spawnNewFruit(std::vector<Vector2<int> > &freePositions);
        const std::vector<Vector2<int> > &getPositions(void) const;

    private:
        std::vector<Vector2<int> > _fruitPositions;
        uint _maxFruitNb;
};

#endif /* !FRUIT_HPP_ */
