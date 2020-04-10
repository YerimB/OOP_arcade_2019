/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacManScene
*/

#include "PacManScene.hpp"

static PacManScene *game = NULL;

PacManScene::PacManScene() :
_isDead(false), _scoreEntered(false), _points(0)
{
    this->_textures = {
        "pacmiam.png", "pac.png", "pokeball.png",
        "ghost.png", "dead_ghost.png", "bricks.png"
    };
    this->_directionInterpreter = {
        std::make_pair<std::string, std::array<int, 2> >("up", {-1, 0}),
        std::make_pair<std::string, std::array<int, 2> >("down", {1, 0}),
        std::make_pair<std::string, std::array<int, 2> >("right", {0, 1}),
        std::make_pair<std::string, std::array<int, 2> >("left", {0, -1}),
    };
    this->initializeMap();
}

void PacManScene::initializeMap(void)
{
    std::string line;
    std::ifstream myfile;

    myfile.open("games/PacMan/map.txt");
    for (int i = 0; std::getline(myfile, line); ++i) {
        for (int j = 0; j < line.length(); ++j) {
            switch (line[j]) {
                case '#':
                    this->_map[j][i] = std::make_shared<Wall>(Vector2<int>(j, i));
                    break;
                case '*':
                    this->_coins.push_back(std::make_shared<PCoin>(Vector2<int>(j, i)));
                    this->_map[j][i] = this->_coins.at(this->_coins.size() - 1);
                    break;
                case 'A':
                    this->_apples.push_back(std::make_shared<Apple>(Vector2<int>(j, i)));
                    this->_map[j][i] = this->_apples.at(this->_apples.size() - 1);
                    break;
                case 'G':
                    this->_ghosts.push_back(std::make_shared<Ghost>(Vector2<int>(j, i), Vector2<int>(-1, 0)));
                    this->_map[j][i] = this->_ghosts.at(this->_ghosts.size() - 1);
                    break;
                case 'P':
                    this->_pacMan = std::make_shared<PacMan>(Vector2<int>(j, i), Vector2<int>(0, 1));
                    this->_map[j][i] = this->_pacMan;
                    break;
                case '\n':
                    break;
                default:
                    this->_map[j][i] = std::make_shared<PVoid>();
            }
        }
    }
    myfile.close();
}

const std::vector<std::string> &PacManScene::getTextures(void) const
{
    return (this->_textures);
}

void PacManScene::moveGhosts(void)
{
    std::array<std::string, 4> dirs ({"up", "down", "right", "left"});

    for (int i = 0; i < 3; ++i) {
        Vector2<int> oldPos = this->_ghosts[i]->getPosition();
        this->_ghosts[i]->move();
        while (_map[this->_ghosts[i]->getPosition().x][this->_ghosts[i]->getPosition().y]->getName() == "wall") {
            this->_ghosts[i]->setPos(oldPos);
            std::string dir = dirs[std::rand()/((RAND_MAX + 1u)/4)];
            this->_ghosts[i]->setDir((Vector2<int>){_directionInterpreter[dir][1], _directionInterpreter[dir][0]});
            this->_ghosts[i]->move();
        }
    }
}

void PacManScene::updateBoard()
{
    std::shared_ptr<IPEntity> _void = std::make_shared<PVoid>();

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (_map[i][j] == nullptr)
                _map[i][j] = _void;
            if (_map[i][j]->getName() != "wall")
                _map[i][j] = _void;
        }
    }
    this->moveGhosts();
    for (int i = 0; i < this->_coins.size(); i++)
        _map[this->_coins[i]->getPosition().x][this->_coins[i]->getPosition().y] = this->_coins[i];
    for (int i = 0; i < this->_ghosts.size(); i++)
        _map[this->_ghosts[i]->getPosition().x][this->_ghosts[i]->getPosition().y] = this->_ghosts[i];
    for (int i = 0; i < this->_apples.size(); i++)
        _map[this->_apples[i]->getPosition().x][this->_apples[i]->getPosition().y] = this->_apples[i];
    _map[_pacMan->getPosition().x][_pacMan->getPosition().y] = _pacMan;
}

void PacManScene::checkApple()
{
    if (_map[_pacMan->getPosition().x][_pacMan->getPosition().y]->getName() == "apple") {
        this->_apples.erase(std::find(
                this->_apples.begin(),
                this->_apples.end(),
                _map[_pacMan->getPosition().x][_pacMan->getPosition().y]
        ));
        for (int i = 0; i < this->_ghosts.size(); i++){
            this->_ghosts[i]->setUber(true);
        }
        compt = 0;
    }
}

void PacManScene::checkGhost()
{
    if (_map[_pacMan->getPosition().x][_pacMan->getPosition().y]->getName() == "ghost") {
        std::vector<std::shared_ptr<Ghost> >::iterator it = std::find(
                this->_ghosts.begin(),
                this->_ghosts.end(),
                _map[_pacMan->getPosition().x][_pacMan->getPosition().y]
        );
        if (it->get()->getState() == true) {
            it->get()->setPos(Vector2<int>(16, 12));
            it->get()->setUber(false);
        } else
            _isDead = true;
    }
}

void PacManScene::checkCoin()
{
    if (_map[_pacMan->getPosition().x][_pacMan->getPosition().y]->getName() == "coin") {
        this->_coins.erase(std::find(
                this->_coins.begin(),
                this->_coins.end(),
                _map[_pacMan->getPosition().x][_pacMan->getPosition().y]
        ));
        this->_points += 1;
    }
}

void PacManScene::checkWall(Vector2<int> oldPos, Vector2<int> oldDir)
{
    if (_map[_pacMan->getPosition().x][_pacMan->getPosition().y]->getName() == "wall") {
        _pacMan->setDir(oldDir);
        _pacMan->setPos(oldPos);
    }
}

void PacManScene::update(const std::string &input)
{
    if (_isDead) return;
    compt += 1;
    if (compt == 100) {
        for (int i = 0; i < this->_ghosts.size(); i++){
            this->_ghosts[i]->setUber(false);
        }
    }
    Vector2<int> oldPos = _pacMan->getPosition();
    Vector2<int> oldDir = _pacMan->getDir();
    if (input.length() > 1 ) {
         _pacMan->setDir((Vector2<int>){_directionInterpreter[input][1], _directionInterpreter[input][0]});
    }
    _pacMan->move();
    checkWall(oldPos, oldDir);
    checkCoin();
    for (int i = 0; i < this->_ghosts.size(); i++){
        _map[this->_ghosts[i]->getPosition().x][this->_ghosts[i]->getPosition().y] = this->_ghosts[i];
    }
    checkGhost();
    checkApple();
    updateBoard();
}

void PacManScene::drawBoard(void)
{
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (_map[i][j] != nullptr) {
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

const std::vector<std::string> &PacManScene::sendInstruction(void)
{
    this->_instructions.clear();
    if (this->_isDead) {
        this->_instructions.push_back("text 'you are dead' 75 25 red");
        this->_instructions.push_back("text 'score: " + std::to_string(this->_points * 10) + "' 30 10 white");
        if (!this->_scoreEntered) {
            this->_instructions.push_back("score " + std::to_string(this->_points * 10));
            this->_scoreEntered = true;
        }
        return (this->_instructions);
    }
    this->drawBoard();
    this->_instructions.push_back("text 'score: " + std::to_string(this->_points * 10) + "' 145 10 white");
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (_map[i][j] != nullptr) {
                this->_instructions.push_back(
                    "rectangle "
                    + std::to_string(i * 4)
                    + " "
                    + std::to_string(j * 2)
                    + " "
                    + "2 4 "
                    + _map[i][j]->getColor()
                );
            }
        }
    }
    return (this->_instructions);
}

extern "C" {
    __attribute__((constructor))
    void ctor()
    {
        game = new PacManScene;
    }

    PacManScene *entryPoint()
    {
        return game;
    }

    __attribute__((destructor))
    void dtor()
    {
        delete (game);
    }
}
