/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SnakeScene
*/

#ifndef SNAKESCENE_HPP_
#define SNAKESCENE_HPP_

#include "../IGame.hpp"
#include "Fruit.hpp"
#include "Void.hpp"
#include "Snake.hpp"
#include "../../lib/Templates/Vector.hpp"

class SnakeScene : public IGame {
    public:
        SnakeScene();
        ~SnakeScene() = default;
        void initializeMap(void) final;
        const std::vector<std::string> &getTextures(void) const final;
        const std::vector<std::string> &sendInstruction() final;
        const std::string getName(void) { return "nibbler2"; };
    
    public:
        enum ETT {
            SHEAD, SBODY,
            FRUIT, VOID,
            WALL
        };
        void update(const std::string &input) final; // Only missing
        void updateMap(void);
        void updateFreePostitions(void);
        const std::string selectColor(const SnakeScene::ETT &type) const;

    private:
        std::vector<std::string> _textures;
        std::vector<std::string> _instructions;
        std::map<const std::string, std::array<int, 2> > _dirInterpreter;

    private:
        std::array<std::array<ETT, 25>, 32> _map;
        std::shared_ptr<Snake> _snake;
        std::shared_ptr<Fruit> _fruits;
        std::vector<Vector2<int> >_freePos;
        bool _isDead;
        bool _scoreEntered;
        std::string _lastInput;
};

#endif /* !SNAKESCENE_HPP_ */
