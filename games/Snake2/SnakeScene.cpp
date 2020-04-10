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
    this->_dirInterpreter = {
        {"up", {0, -1}},
        {"down", {0, 1}},
        {"right", {1, 0}},
        {"left", {-1, 0}},
    };
    this->initializeMap();
}

void SnakeScene::initializeMap(void)
{
    for (int i = 0; i < this->_map.size(); ++i)
        for (int j = 0; j < this->_map[i].size(); ++j)
            this->_map[i][j] = SnakeScene::VOID;
    this->_snake = std::make_shared<Snake>(
        Vector2<int>(this->_map.size() / 2, this->_map[0].size() / 2)
    );
    this->updateMap();
    this->_fruits = std::make_shared<Fruit>(this->_freePos);
    this->updateMap();
}

const std::vector<std::string> &SnakeScene::getTextures(void) const
{
    return (this->_textures);
}

/////////////// IN LOOP FUNCTIONS ///////////////

void SnakeScene::update(const std::string &input)
{
    Vector2<int> d(0, 0);
    Vector2<int> fpos(0, 0);

    if (this->_isDead)
        return;
    else if (this->_dirInterpreter.find(input) != this->_dirInterpreter.end()/* && \
    (input == "up" && this->_lastInput != "down") || (input == "down" && this->_lastInput != "up") || \
    (input == "left" && this->_lastInput != "right") || (input == "right" && this->_lastInput != "left")*/)
        this->_lastInput = input;
    d.x = _dirInterpreter[_lastInput][0];
    d.y = _dirInterpreter[_lastInput][1];
    fpos = Vector2<int>(_snake->getHeadPosition().x + d.x, _snake->getHeadPosition().y + d.y);
    switch (this->_map[fpos.x][fpos.y]) {
        case SnakeScene::FRUIT:
            this->_snake->grow();
            this->_fruits->getConsumed(fpos);
            break;
        case SnakeScene::SBODY:
            this->_isDead = true;
            return;
        default: break;
    }
    if (fpos.x < 0 || fpos.x >= this->_map.size() || \
    fpos.y < 0 || fpos.y >= this->_map[0].size()) {
        this->_isDead = true;
        return;
    }
    this->_snake->move(d);
    this->updateMap();
    std::cout << "update !" << std::endl;
}

void SnakeScene::updateMap(void)
{
    Vector2<int> tmp(-1, -1);

    for (int i = 0; i < this->_map.size(); ++i)
        for (int j = 0; j < this->_map[i].size(); ++j)
            this->_map[i][j] = SnakeScene::VOID;
    if (this->_snake) {
        tmp = this->_snake->getHeadPosition();
        this->_map[tmp.x][tmp.y] = SnakeScene::SHEAD;
        for (const auto &elem : this->_snake->getBodyPositions())
            this->_map[elem.x][elem.y] = SnakeScene::SBODY;
    }
    if (this->_fruits)
        for (const auto &elem : this->_fruits->getPositions())
            this->_map[elem.x][elem.y] = SnakeScene::FRUIT;
    this->updateFreePostitions();
}

void SnakeScene::updateFreePostitions(void)
{
    this->_freePos.clear();
    for (int i = 0; i < this->_map.size(); ++i)
        for (int j = 0; j < this->_map[i].size(); ++j)
            if (this->_map[i][j] == SnakeScene::VOID)
                this->_freePos.push_back(Vector2<int>(i, j));
}

/////////////// INSTRUCTIONS ///////////////

const std::string SnakeScene::selectColor(const SnakeScene::ETT &type) const
{
    switch (type) {
        case SnakeScene::SHEAD:
            return (this->_snake->getColor("head", this->_lastInput));
        case SnakeScene::SBODY:
            return (this->_snake->getColor());
        case SnakeScene::FRUIT:
            return ("yellow:grape.jpg°0");
        default: return ("white");
    }
}

const std::vector<std::string> &SnakeScene::sendInstruction(void)
{
    this->_instructions.clear();

    std::cout << "Getting instructions" << std::endl;
    // When player dies, differents instructions
    if (this->_isDead) {
        this->_instructions.push_back("text 'you are dead' 75 25 red");
        if (!this->_scoreEntered) {
            this->_instructions.push_back("score " + \
            std::to_string((this->_snake->getLength() - 1) * 10));
            this->_scoreEntered = true;
        }
        return (this->_instructions);
    }

    // Draw map instructions
    for (int i = 0; i < this->_map.size(); ++i)
        for (int j = 0; j < this->_map[i].size(); ++j) {
            this->_instructions.push_back(
                "rectangle " + std::to_string(i * 4) + " "
                + std::to_string(j * 2) + " 2 4 white"
            );
            if (this->_map[i][j] != SnakeScene::VOID)
                this->_instructions.push_back(
                    "rectangle " + std::to_string(i * 4) + " "
                    + std::to_string(j * 2) + " 2 3 "
                    + this->selectColor(this->_map[i][j])
                );
        }
    
    // Draw actual score
    this->_instructions.push_back("text 'score: " + \
    std::to_string((this->_snake->getLength() - 1) * 10) + "' 145 10 white");
    std::cout << "Sending instructions" << std::endl;
    return (this->_instructions);
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