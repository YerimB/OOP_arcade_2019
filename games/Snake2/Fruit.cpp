/*
** EPITECH PROJECT, 2020
** games
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::vector<Vector2<int> > &freePos, const uint &maxFruits) :
_maxFruitNb(maxFruits)
{
    int e = -1;

    std::srand(std::time(nullptr));
    for (uint i = 0; i < this->_maxFruitNb; ++i)
        this->spawnNewFruit(freePos);
}

void Fruit::getConsumed(const Vector2<int> &p)
{
    for (uint i = 0; i < this->_fruitPositions.size(); ++i)
        if (this->_fruitPositions[i].x == p.x \
        && this->_fruitPositions[i].y == p.y) {
            this->_fruitPositions.erase(this->_fruitPositions.begin() + i);
            break;
        }
}

void Fruit::spawnNewFruit(std::vector<Vector2<int> > &freePos)
{
    int e = (std::rand() % freePos.size());

    this->_fruitPositions.push_back(Vector2<int>(freePos[e].x, freePos[e].y));
    freePos.erase(freePos.begin() + e);
}

const std::vector<Vector2<int> > &Fruit::getPositions(void) const
{
    return (this->_fruitPositions);
}