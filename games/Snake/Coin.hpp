/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Coin
*/

#ifndef TEK2_COIN_HPP
#define TEK2_COIN_HPP

#include "IEntity.hpp"

class Coin: public IEntity {
    public:
        Coin() {};
        const std::string getName() const final;
        const std::string getColor() const final;
};


#endif //TEK2_COIN_HPP
