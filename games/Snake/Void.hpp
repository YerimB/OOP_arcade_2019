//
// Created by Yuno on 05/03/2020.
//

#ifndef TEK2_VOID_HPP
#define TEK2_VOID_HPP

#include "IEntity.hpp"

class Void: public IEntity {
public:
    Void() {};
    std::string getName() final;
    std::string getColor() final;
};


#endif //TEK2_VOID_HPP
