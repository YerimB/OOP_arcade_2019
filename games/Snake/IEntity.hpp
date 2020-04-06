/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IEntity
*/

#ifndef TEK2_IENTITY_HPP
#define TEK2_IENTITY_HPP

#include "../../lib/Templates/Vector.hpp"
#include <iostream>
#include <vector>

class IEntity {
    public:
        virtual const std::string getName(void) const = 0;
        virtual const std::string getColor(void) const = 0;
        virtual ~IEntity() = default;
};

#endif //TEK2_IENTITY_HPP
