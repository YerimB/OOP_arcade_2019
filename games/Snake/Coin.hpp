//
// Created by Yuno on 05/03/2020.
//

#ifndef TEK2_COIN_HPP
#define TEK2_COIN_HPP

#include "IEntity.hpp"

class Coin: public IEntity {
public:
    Coin() {};
    std::string getName() final;
    std::string getColor() final;
};


#endif //TEK2_COIN_HPP
