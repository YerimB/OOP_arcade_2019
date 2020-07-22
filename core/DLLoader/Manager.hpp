/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Manager
*/

#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include "../../lib/IGraphics.hpp"
#include "DLLoader.hpp"
#include "../GameModule/GameModule.hpp"
#include "../Exceptions/ArcadeException.hpp"
#include "../Launcher.hpp"
#include <map>
#include <string>
#include <memory>
#include <regex>
#include <dirent.h>
#include <fstream>

class Manager {
    public:
        Manager(const std::string &defaultLib);
        ~Manager();
        void ChangeLibrary(const std::string &);
        void ExecuteInstructions(void);
        void LoadTextures(void);
        IGraphics &GetInstance(void);
        void updateScore(std::string score);

    private:
        const std::string GetLibraryName(const std::string &path) const;
        bool IsLibrary(const std::string& file) const;

    private:
        bool _launched;
        std::string _currentLib;
        Rectangle<int> _posSize;
        std::unique_ptr<Launcher> _launcher;
        std::unique_ptr<GameModule> _gameCore;
        std::map<std::string, std::unique_ptr<DLLoader<IGraphics> > > _libraries;
        std::string _username;
        std::vector<std::string> _instructions;
        std::string _instructionType;
        std::string _event;
        std::string _textToWrite;
};

#endif /* !MANAGER_HPP_ */
