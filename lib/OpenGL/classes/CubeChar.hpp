/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CubeChar
*/

#ifndef CUBECHAR_HPP_
#define CUBECHAR_HPP_

#include "Cube.hpp"
#include <map>

class CubeChar : public Cube {
    public:
        CubeChar(const glm::vec3 &position = glm::vec3(0.0f, 0.0f, 0.0f),
            const glm::vec3 &rotation = glm::vec3(0.0f, 0.0f, 0.0f),
            const glm::vec3 &scalation = glm::vec3(1.0f, 1.0f, 1.0f));
        ~CubeChar() = default;
        void addLetter(const char &letter, const std::shared_ptr<Texture> &texture);
        const bool setLetter(const char &letter);

    private:
        std::map<char, std::shared_ptr<Texture> > _textures;
};

#endif /* !CUBECHAR_HPP_ */
