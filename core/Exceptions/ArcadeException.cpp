/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeException
*/

#include "ArcadeException.hpp"

/**
 * @brief ArcadeException Constructor
 * 
 * @param component Source of the exception
 * @param what Error message for this exception
 * 
 * @return New instance of ArcadeException
 */
ArcadeException::ArcadeException(const std::string &component, const std::string &what) :
_component(component), _what(what) {}

DLException::DLException(const std::string &component, const std::string &what) :
ArcadeException(component, what) {}