/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Launcher
*/

#include "Launcher.hpp"

/**
 * @brief Launcher constructor
 * 
 * Init Launcher and scan ./games directory to discover __.so games
 * Games are sorted alphabetically
 * 
 * @return New instance of Launcher
 */
Launcher::Launcher()
{
    std::string tmp;
    std::string line;
    std::string game;
    std::string score;
    std::string name;

    this->_gameSelection = true;
    for (const auto &entry : std::filesystem::directory_iterator("./games")) {
        tmp = entry.path().string();
        if (tmp.compare(tmp.length() - 3, 3, ".so") == 0)
            this->_games.push_back(tmp);
    }
    std::sort(
        this->_games.begin(),
        this->_games.end(),
        [](const std::string &a, const std::string &b) { return (a < b); } // Lambda to sort
    );
    std::ifstream scorefile;
    scorefile.open("score.txt");
    if (scorefile.is_open()) {
        while (std::getline(scorefile, line)) {
            game = line.substr(0, line.find("|"));
            line = line.substr(line.find("|") + 1);
            name = line.substr(0, line.find("|"));
            line = line.substr(line.find("|") + 1);
            _scores[std::stoi(line)] = game + "->" + name;
        }
    }
    this->_currentIndex = 0;
    this->_selectedIndex = -1;
}

const std::string Launcher::formatText(const std::string &text) const
{
    std::string tmp = text.substr(19);

    return (tmp.substr(0, tmp.find(".so")));
}

const std::string Launcher::getColor(const int &index) const
{
    if (index == this->_currentIndex)
        return ("yellow");
    else if (index == this->_selectedIndex)
        return ("red");
    return ("white");
}

const std::vector<std::string> &Launcher::getInstructions(const std::string &event)
{
    this->_instructions.clear();
    int nb = 0;
    if (event == "e") {
        if (!this->_gameSelection) {
            this->_instructions.push_back("load " + _games[_currentIndex]);
            return (this->_instructions);
        }
        this->_gameSelection = false;
    }
    if (this->_gameSelection) {
        updateIndex(event);
        this->_instructions.push_back("text 'CHOSE GAME' 70 10 white");
        this->_instructions.push_back("text 'press e to continue' 70 14 blue");
        for (int i = 0; i < _games.size(); ++i)
            this->_instructions.push_back("text '" + formatText(_games[i]) \
            + "' 70 " + std::to_string(25 + (i * 5)) + " " + getColor(i));
    } else {
        this->_instructions.push_back("text 'press space to continue' 70 10 blue");
        this->_instructions.push_back("text 'name:' 30 30 white");
        this->_instructions.push_back("getstr text");
        this->_instructions.push_back("text 'best scores:' 30 35 white");
        for (auto it = _scores.rbegin(); it != _scores.rend(); it++) {
            if (nb == 3) break;
            if (it->second.substr(0, it->second.find("->") - 1) == formatText(_games[_currentIndex])) {
                _instructions.push_back(
                    "text '"
                    + it->second.substr(it->second.find("'") + 1, it->second.substr(it->second.find("'") + 1).find("'"))
                    + "\t\t" + std::to_string(it->first)
                    + "' 40 "
                    + std::to_string(40 + (5 * nb))
                    + " green"
                );
                nb++;
            }
        }
    }
    return (this->_instructions);
}

void Launcher::updateIndex(const std::string &direction)
{
    if (direction == "down" && _currentIndex + 1 != _games.size())
        _currentIndex += 1;
    else if (direction == "up" && _currentIndex - 1 >= 0)
        _currentIndex -= 1;
}