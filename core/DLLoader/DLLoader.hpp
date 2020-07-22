/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <memory>
#include "../GameModule/IGameModule.hpp"
#include "../DynamicLibrary/DynamicLibrary.hpp"
#include "../../lib/IGraphics.hpp"
#include "../../games/IGame.hpp"

template<typename T>
class DLLoader {
    public:
        DLLoader(const std::string &file,  const DynamicLibrary::LibraryType &type = DynamicLibrary::Graphic);
        ~DLLoader();
        T &GetInstance();

    private:
        DynamicLibrary _libLoader;
        void *_handle = NULL;
        T *_instance;
};

#endif /* !DLLOADER_HPP_ */
