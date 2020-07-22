//
// Created by Yuno on 11/03/2020.
//

#ifndef TEK2_PACMAN_HPP
#define TEK2_PACMAN_HPP

#include "IEntity.hpp"

class PacMan: public IPEntity {
public:
    PacMan(Vector2<int> pos, Vector2<int> dir): _pos(pos), _dir(dir) {};
    Vector2<int> getPosition();
    Vector2<int> getDir();
    std::string getName();
    void setPos(Vector2<int>);
    std::string getColor();
    void move();
    void setDir(Vector2<int>);


private:
    Vector2<int> _pos;
    Vector2<int> _dir;
};


#endif //TEK2_PACMAN_HPP
