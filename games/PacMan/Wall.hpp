//
// Created by Yuno on 11/03/2020.
//

#ifndef TEK2_WALL_HPP
#define TEK2_WALL_HPP

#include "IEntity.hpp"

class Wall: public IPEntity {
public:
    Wall(Vector2<int> pos): _pos(pos) {};
    Vector2<int> getPosition();
    std::string getName();
    std::string getColor();

private:
    Vector2<int> _pos;
    bool _isPackManUber;
};


#endif //TEK2_WALL_HPP
