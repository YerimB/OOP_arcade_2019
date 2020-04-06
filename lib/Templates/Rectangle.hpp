/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

template<typename T>
struct Rectangle
{
    Rectangle(const T &_p1, const T &_p2, const T &_p3, const T &_p4)
    {
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
        p4 = _p4;
    }
    ~Rectangle() = default;

    void SetPosition(const T &_p1, const T &_p2, const T &_p3, const T &_p4)
    {
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
        p4 = _p4;
    };

    T p1;
    T p2;
    T p3;
    T p4;

};

#endif /* !RECTANGLE_HPP_ */
