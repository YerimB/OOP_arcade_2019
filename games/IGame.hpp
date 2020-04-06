/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#ifndef TEK2_IGAME_HPP
#define TEK2_IGAME_HPP

#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <memory>

class IGame {
    public:
        virtual const std::string getName() = 0;
        virtual const std::vector<std::string> &getTextures(void) = 0;
        virtual void initializeMap(void) = 0;
        virtual void update(const std::string &input) = 0;
        virtual const std::vector<std::string> &sendInstruction(void) = 0;
        virtual ~IGame() = default;
};

#endif //TEK2_IGAME_HPP
