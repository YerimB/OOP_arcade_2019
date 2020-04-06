/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "DLLoader/DLLoader.hpp"
#include "DLLoader/Manager.hpp"
#include "GameModule/GameModule.hpp"
#include <memory>
#include <vector>
#include <thread>
#include "Launcher.hpp"

int main(int ac, char **av)
{
    std::unique_ptr<Manager> manager = nullptr;
    auto wait_time = std::chrono::milliseconds(70);

    if (ac != 2)
        std::exit(84);
    manager = std::make_unique<Manager>(std::string(av[1]));
    while (true) {
        manager->ExecuteInstructions();
        if (!manager->GetInstance().isOpen())
            return(0);
        manager->GetInstance().drawWindow();
        std::this_thread::sleep_for(wait_time);
        manager->GetInstance().clearWindow();
    }
}