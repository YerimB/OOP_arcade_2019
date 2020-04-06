/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameModule
*/

#include "GameModule.hpp"

/**
 * @brief GameModule constructor
 * 
 * Load the game passed as parameter using DLLoader
 * 
 * @param path Path to the game library .so
 * 
 * @return New instance of GameModule
 */
GameModule::GameModule(const std::string &path)
{
    this->_gameLoader = std::make_unique<DLLoader<IGame> >(path);
}

/**
 * @brief Get instructions to execute from the game
 * 
 * @param input User input
 * @return A std::vector\<std::string> containing instructions
 */
const std::vector<std::string> GameModule::getInstruction(std::string input) const
{
    this->_gameLoader->GetInstance().update(input);
    return (this->_gameLoader->GetInstance().sendInstruction());
}

/**
 * @brief Get textures from the game
 * 
 * Get all textures used in the game
 * 
 * @return A std::vector\<std::string> containing all textures
 */
const std::vector<std::string> GameModule::getTextures(void) const
{
    return (this->_gameLoader->GetInstance().getTextures());
}

const std::string GameModule::getName()
{
    return this->_gameLoader->GetInstance().getName();
}