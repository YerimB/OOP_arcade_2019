//
// Created by Yuno on 11/03/2020.
//

#ifndef TEK2_APPLE_HPP
#define TEK2_APPLE_HPP

#include "IEntity.hpp"

class Apple: public IPEntity {
public:
    Apple(Vector2<int> pos): _pos(pos) {};
    Vector2<int> getPosition();
    std::string getName();
    std::string getColor();

private:
    Vector2<int> _pos;
};


#endif //TEK2_APPLE_HPP
