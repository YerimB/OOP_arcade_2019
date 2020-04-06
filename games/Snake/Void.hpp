/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Void
*/

#ifndef TEK2_VOID_HPP
#define TEK2_VOID_HPP

#include "IEntity.hpp"

class Void: public IEntity {
    public:
        Void() {};
        const std::string getName() const final;
        const std::string getColor() const final;
};


#endif //TEK2_VOID_HPP
