/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

template<typename T>
struct Vector2 {
    Vector2(const T &_x, const T &_y)
    {
        x = _x;
        y = _y;
    };
    ~Vector2() = default;

    void SetPosition(const T &_x, const T &_y) {
        x = _x;
        y = _y;
    };

    T x;
    T y;
};

template struct Vector2<int>;

#endif /* !VECTOR_HPP_ */
