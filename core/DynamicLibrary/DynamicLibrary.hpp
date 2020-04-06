/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DynamicLibrary
*/

#ifndef DYNAMIC_LIBRARY_HPP
#define DYNAMIC_LIBRARY_HPP

#include <string>
#include <dlfcn.h>
#include <iostream>
#include "../Exceptions/ArcadeException.hpp"

class DynamicLibrary
{
    public:
        enum LibraryType {
            Graphic,
            Game
        };

    public:
        DynamicLibrary() = default;
        ~DynamicLibrary() = default;

    public:
        void *Open(const std::string &file, const int &flags);
        const std::size_t Close(void *handle);
        void *GetSymbol(void *handle, const std::string &symbol);
};

#endif