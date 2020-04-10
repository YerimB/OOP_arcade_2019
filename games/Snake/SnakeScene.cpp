/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SnakeScene
*/

#include "SnakeScene.hpp"

static SnakeScene *game = NULL;

SnakeScene::SnakeScene() :
_isDead(false), _scoreEntered(false), _lastInput("right")
{
    this->_textures = { "pokeball.png", "frolian.png", "grape.jpg" };
    this->_directionInterpreter = {
        std::make_pair<std::string, std::array<int, 2> >("up", {-1, 0}),
        std::make_pair<std::string, std::array<int, 2> >("down", {1, 0}),
        std::make_pair<std::string, std::array<int, 2> >("right", {0, 1}),
        std::make_pair<std::string, std::array<int, 2> >("left", {0, -1}),
    };
    this->_snake.push_back(std::make_shared<Snake>(Vector2<int>(1, 0), Vector2<int>(16, 16)));
    this->initializeMap();
}

void SnakeScene::initializeMap(void)
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < 32; ++i)
        for (int j = 0; j < 25; ++j)
            this->_map[i][j] = std::make_shared<Void>();
    for (int i = 0, x = 0, y = 0; i < 10; ++i) {
        x = std::rand() % 32;
        y = std::rand() % 25;
        this->_map[x][y] = std::make_shared<Coin>();
    }
}

void SnakeScene::updateSnakePos()
{
    for (int i = 0; i < 32; ++i)
        for (int j = 0; j < 25; ++j)
            if (this->_map[i][j]->getName() == "Snake")
                this->_map[i][j] = std::make_shared<Void>();
    for (int i = 0; i < this->_snake.size(); ++i)
        this->_map[this->_snake[i]->getPos().y][this->_snake[i]->getPos().x] = this->_snake[i];
}

void SnakeScene::growSnake(std::vector<std::shared_ptr<Snake> > &new_snake, Vector2<int> new_pos)
{
    for (int i = 0; i < this->_snake.size(); i++)
        new_snake.push_back(this->_snake[i]);
    if (this->_map[new_pos.y][new_pos.x]->getName() == "Snake") {
        this->_isDead = true;
        return;
    }
    if (this->_map[new_pos.y][new_pos.x]->getName() != "coin")
        new_snake.pop_back();
    else {
        this->_map[std::rand() % 32][std::rand() % 25] = std::make_shared<Coin>();
    }
    this->_snake = new_snake;
    updateSnakePos();
}

void SnakeScene::update(const std::string &input)
{
    std::array<int, 2> dir = {0, 0};

    if (this->_directionInterpreter.find(input) != this->_directionInterpreter.end() && \
    (input == "up" && this->_lastInput != "down") || (input == "down" && this->_lastInput != "up") || \
    (input == "left" && this->_lastInput != "right") || (input == "right" && this->_lastInput != "left"))
        this->_lastInput = input;
    dir = this->_directionInterpreter[this->_lastInput];
    this->_snake[0]->unsetHead();
    Vector2<int> new_pos(
        this->_snake[0]->getPos().x + dir[0],
        this->_snake[0]->getPos().y + dir[1]
    );
    if (new_pos.x < 0 || new_pos.x >= 25 || new_pos.y < 0 || new_pos.y >= 32) {
        this->_isDead = true;
        return;
    }
    std::vector<std::shared_ptr<Snake> > new_snake;
    new_snake.push_back(std::make_shared<Snake>(Vector2<int>(dir[1], dir[0]), new_pos));
    growSnake(new_snake, new_pos);
}

const std::vector<std::string> &SnakeScene::getTextures(void) const
{
    return (this->_textures);
}

void SnakeScene::drawBoard(void)
{
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 25; j++) {
            if (this->_map[i][j] != nullptr) {
                this->_instructions.push_back(
                    "rectangle "
                    + std::to_string(i * 4)
                    + " "
                    + std::to_string(j * 2)
                    + " "
                    + "2 4 "
                    + "white"
                );
            }
        }
    }
}

const std::vector<std::string> &SnakeScene::sendInstruction(void)
{
    this->_instructions.clear();
    if (this->_isDead) {
        this->_instructions.push_back("text 'you are dead' 75 25 red");
        if (!this->_scoreEntered) {
            this->_instructions.push_back("score " + std::to_string(this->_snake.size() * 10));
            this->_scoreEntered = true;
        }
        return this->_instructions;
    }
    this->drawBoard();
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 25; j++) {
            if (this->_map[i][j]->getName() != "void")
                this->_instructions.push_back(
                    "rectangle "
                    + std::to_string(i * 4)
                    + " "
                    + std::to_string(j * 2)
                    + " "
                    + "2 3 "
                    + this->_map[i][j]->getColor()
                );
        }
    }
    this->_instructions.push_back("text 'score: " + \
    std::to_string(this->_snake.size() * 10) + "' 145 10 white");
    return this->_instructions;
}

extern "C" {
    __attribute__((constructor))
    void ctor()
    {
        game = new SnakeScene;
    }

    SnakeScene *entryPoint()
    {
        return game;
    }

    __attribute__((destructor))
    void dtor()
    {
        delete (game);
    }
}