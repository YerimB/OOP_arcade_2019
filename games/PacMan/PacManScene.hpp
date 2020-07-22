//
// Created by Yuno on 11/03/2020.
//

#ifndef TEK2_PACMANSCENE_HPP
#define TEK2_PACMANSCENE_HPP

#include "Ghost.hpp"
#include "Coin.hpp"
#include "Apple.hpp"
#include "PacMan.hpp"
#include "Wall.hpp"
#include "PVoid.hpp"
#include <algorithm>
#include <fstream>
#include "../IGame.hpp"
#include <array>
#include <vector>
#include <map>

class PacManScene: public IGame {
    public:
        PacManScene();
        void initializeMap(void) final;
        void drawBoard(void);
        const std::vector<std::string> &sendInstruction(void) final;
        inline const std::string getName() { return "pacman"; };
        const std::vector<std::string> &getTextures(void) final;
        ~PacManScene() = default;

    public: // Game methods
        void update(const std::string &input) final;
        void updateBoard(void);
        void checkApple(void);
        void checkGhost(void);
        void checkCoin(void);
        void fillCoin(void);
        void checkWall(Vector2<int> oldPos, Vector2<int> oldDir);
        void moveGhosts(void);

    private:
        std::vector<std::string> _textures;
        std::array<std::array<std::shared_ptr<IPEntity>, 32 >, 32> _map;
        std::vector<std::shared_ptr<Apple> > _apples;
        std::vector<std::shared_ptr<PCoin> > _coins;
        std::vector<std::shared_ptr<Ghost> > _ghosts;
        std::shared_ptr<PacMan> _pacMan;
        std::map<std::string, std::array<int, 2> > _directionInterpreter;
        std::vector<std::string> _instructions;
        int compt = 101;
    
    private: // Game vars
        bool _isDead;
        bool _scoreEntered;
        int _points;
};

#endif //TEK2_PACMANSCENE_HPP
