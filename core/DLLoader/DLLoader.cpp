/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#include "DLLoader.hpp"

/**
 * Create and load an instance of a dynamic library
 * 
 * @param file Path to dynamic library
 * @param type Dynamic library type (Graphic or Game)
 */
template<typename T>
DLLoader<T>::DLLoader(const std::string &file, const DynamicLibrary::LibraryType &type)
{
    try {
        this->_handle = this->_libLoader.Open(file, RTLD_LAZY);
    } catch (const DLException &e) {
        std::cerr << "[" << e.GetComponent() << "] " << e.what() << std::endl;
        std::exit(84);
    }

    if (type == DynamicLibrary::Graphic || type == DynamicLibrary::Game)
        this->_instance = reinterpret_cast<T *(*)()>(this->_libLoader.GetSymbol(this->_handle, "entryPoint"))();
    else {
        std::cerr << "[DLLoader] Unknown library type." << std::endl;
        std::exit(84);
    }
    if (this->_instance == nullptr)
        std::exit(84);
}

template<typename T>
DLLoader<T>::~DLLoader()
{
    try {
        this->_libLoader.Close(this->_handle);
    } catch (const DLException &e) {
        std::cerr << "[" << e.GetComponent() << "] " << e.what() << std::endl;
        std::exit(84);
    }
    if (this->_instance != nullptr)
        this->_instance = nullptr;
}

/**
 * @brief Get instance of a Dynamic Library
 * 
 * If the instance is null, an ArcadeException is thrown.
 * 
 * @return A reference of type T to the instance of the Dynamic Library
 */
template<typename T>
T &DLLoader<T>::GetInstance()
{
    if (!this->_instance)
        throw ArcadeException("DLLoader::GetInstance", \
        "Dynamic Library instance null or not found.");
    return *this->_instance;
}

template class DLLoader<IGraphics>;
template class DLLoader<IGame>;