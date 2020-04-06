//
// Created by Yuno on 05/03/2020.
//

#ifndef TEK2_SNAKE_HPP
#define TEK2_SNAKE_HPP

#include "IEntity.hpp"

class Snake : public IEntity{
public:
    Snake(Vector2<int>, Vector2<int>);
    std::string getName() final;
    Vector2<int> getPos();
    void unsetHead();
    std::string getColor() final ;

private:
    bool _isHead;
    Vector2<int> _dir;
    Vector2<int> _pos;
};


#endif //TEK2_SNAKE_HPP
