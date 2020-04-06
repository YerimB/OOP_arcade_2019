/*
** EPITECH PROJECT, 2020
** test8
** File description:
** Cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "Object.hpp"

class Cube : public Object {
    public:
        Cube(const glm::vec3 &position = glm::vec3(0.0f, 0.0f, 0.0f),
            const glm::vec3 &rotation = glm::vec3(0.0f, 0.0f, 0.0f),
            const glm::vec3 &scalation = glm::vec3(1.0f, 1.0f, 1.0f));
        ~Cube() = default;

    protected:
    private:
};

#endif /* !CUBE_HPP_ */
