/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SnakeScene
*/

#ifndef TEK2_SNAKESCENE_HPP
#define TEK2_SNAKESCENE_HPP

#include "../IGame.hpp"
#include "Coin.hpp"
#include "Void.hpp"
#include "Snake.hpp"

class SnakeScene: public IGame {
    public:
        SnakeScene();
        void initializeMap(void) final;
        void drawBoard(void);
        const std::vector<std::string> &sendInstruction() final;
        const std::vector<std::string> &getTextures(void) const final;
        const std::string getName(void) { return "nibbler"; };
        ~SnakeScene() = default;

    public: // Game methods
        void update(const std::string &input) final;
        void updateSnakePos(void);
        void growSnake(std::vector<std::shared_ptr<Snake> > &new_snake, Vector2<int> new_pos);

    private:
        std::array<std::array<std::shared_ptr<IEntity>, 32 >, 32> _map;
        std::map<std::string, std::array<int, 2> > _directionInterpreter;
        std::vector<std::shared_ptr<Snake> > _snake;
        std::vector<std::string> _textures;
        std::vector<std::string> _instructions;
    
    private:
        bool _isDead;
        bool _scoreEntered;
        std::string _lastInput;
};

#endif //TEK2_SNAKESCENE_HPP