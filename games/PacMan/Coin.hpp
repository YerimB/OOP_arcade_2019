//
// Created by Yuno on 11/03/2020.
//

#ifndef TEK2_COIN_HPP
#define TEK2_COIN_HPP

#include "IEntity.hpp"

class PCoin: public IPEntity {
public:
    PCoin(Vector2<int> pos): _pos(pos) {};
    Vector2<int> getPosition();
    std::string getName();
    std::string getColor();

private:
    Vector2<int> _pos;
};


#endif //TEK2_COIN_HPP
