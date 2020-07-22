/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeException
*/

#ifndef ARCADEEXCEPTION_HPP_
#define ARCADEEXCEPTION_HPP_

#include <exception>
#include <string>

class ArcadeException : public std::exception
{
    public:
        ArcadeException(const std::string &component, const std::string &what);
        ~ArcadeException() = default;

    public:
        inline const std::string &GetComponent() const { return _component; };
        inline const char *what() const throw() { return _what.c_str(); };

    protected:
        const std::string _component;
        const std::string _what;
};

class DLException : public ArcadeException
{
    public:
        DLException(const std::string &component, const std::string &what);
};

#endif /* !ARCADEEXCEPTION_HPP_ */
