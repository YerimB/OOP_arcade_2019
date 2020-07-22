//
// Created by Yuno on 05/03/2020.
//

#ifndef TEK2_IENTITY_HPP
#define TEK2_IENTITY_HPP

#include "../../lib/Templates/Vector.hpp"
#include <iostream>

class IEntity {
public:
    virtual std::string getName() = 0;
    virtual std::string getColor() = 0;
    virtual ~IEntity() = default;
};

#endif //TEK2_IENTITY_HPP
