//
// Created by Yuno on 12/03/2020.
//

#ifndef TEK2_PVOID_HPP
#define TEK2_PVOID_HPP

#include "IEntity.hpp"

class PVoid: public IPEntity {
public:
    PVoid(): _pos(Vector2<int>(0, 0)){};
    std::string getName() final;
    std::string getColor() final;
    Vector2<int> getPosition();
private:
    Vector2<int> _pos;
};


#endif //TEK2_PVOID_HPP
