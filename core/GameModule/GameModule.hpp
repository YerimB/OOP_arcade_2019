/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameModule
*/

#ifndef GAMEMODULE_HPP_
#define GAMEMODULE_HPP_

#include "IGameModule.hpp"
#include "../DLLoader/DLLoader.hpp"
#include "../../games/IGame.hpp"

class GameModule : public IGameModule {
    public:
        GameModule(const std::string &path);
        const std::vector<std::string> getInstruction(std::string input) const;
        const std::vector<std::string> getTextures(void) const;
        const std::string getName(void);

    private:
        std::unique_ptr<DLLoader<IGame> > _gameLoader;
};

#endif /* !GAMEMODULE_HPP_ */
