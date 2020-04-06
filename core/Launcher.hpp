/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Launcher
*/

#ifndef TEK2_LAUNCHER_HPP
#define TEK2_LAUNCHER_HPP

#include <vector>
#include <iostream>
#include <ftw.h>
#include <fnmatch.h>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <map>

class Launcher {
    public:
        Launcher();
        const std::vector<std::string> &getInstructions(const std::string &event);
        void updateIndex(const std::string &direction);
        const std::string formatText(const std::string &text) const;
        const std::string getColor(const int &index) const;

    private:
        bool _gameSelection;
        int _currentIndex;
        int _selectedIndex;
        std::map<int, std::string> _scores;
        std::vector<std::string> _games;
        std::vector<std::string> _instructions;
};


#endif //TEK2_LAUNCHER_HPP
