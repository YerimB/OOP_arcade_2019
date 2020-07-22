//
// Created by Yuno on 11/03/2020.
//

#ifndef TEK2_GHOST_HPP
#define TEK2_GHOST_HPP

#include "IEntity.hpp"

class Ghost: public IPEntity {
public:
    Ghost(Vector2<int> pos, Vector2<int> dir): _pos(pos), _dir(dir) {};
    Vector2<int> getPosition();
    Vector2<int> getDir();
    void setDir(Vector2<int> dir);
    void setPos(Vector2<int> dir);
    std::string getName();
    std::string getColor();
    void setUber(bool);
    void move();
    bool getState();

private:
    Vector2<int> _pos;
    Vector2<int> _dir;
    bool _isPackManUber;
};


#endif //TEK2_GHOST_HPP
