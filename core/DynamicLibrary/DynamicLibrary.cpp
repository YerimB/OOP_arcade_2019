/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DynamicLibrary
*/

#include "DynamicLibrary.hpp"

/**
 * @brief Open a Dynamic Library
 * 
 * Open a Dynamic Library using `dlopen()`
 * If `dlopen()` fail, a DLException is thrown. The error message contains `dlerror()` information
 * 
 * @param file Path to .so file
 * @param flags Flags to use with `dlopen()`
 * 
 * @return A pointer to the beginning of the Dynamic Library
 */
void *DynamicLibrary::Open(const std::string &file, const int &flags)
{
    void *handle = nullptr;

    if ((handle = dlopen(file.c_str(), flags)) == nullptr)
        throw DLException("DynamicLibrary::Open", "Cannot open " + file + ". " + std::string(dlerror()));

    return handle;
}

/**
 * @brief Close a Dynamic Library using `dlclose()`
 * 
 * Close a Dynamic Library using `dlclose()`
 * If `dlclose()` fail, a DLException is thrown. The error message contains `dlerror()` information
 * 
 * @param handle A handle to a Dynamic Library
 * 
 * @return -1 if handle is null, 0 otherwise
 */
const std::size_t DynamicLibrary::Close(void *handle)
{
    if (handle == nullptr)
        return (-1);
    if (dlclose(handle) != 0)
        throw DLException("Close", "Failed to close the library." + std::string(dlerror()));

    return (0);
}

/**
 * @brief Get a symbol from a Dynamic Library using `dlsym()`
 * 
 * Get a pointer to a function of the Dynamic Library
 * 
 * @param handle A handle to a Dynamic Library
 * @param symbol Function name
 * 
 * @return A pointer to the function
 */
void *DynamicLibrary::GetSymbol(void *handle, const std::string &symbol)
{
    if (handle == nullptr)
        return nullptr;

    void *sym = dlsym(handle, symbol.c_str());

    if (sym == nullptr)
    {
        std::exit(84);
    }

    return sym;
}
