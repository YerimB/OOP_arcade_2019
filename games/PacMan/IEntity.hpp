//
// Created by Yuno on 05/03/2020.
//

#ifndef TEK2_IPENTITY_HPP
#define TEK2_IPENTITY_HPP

#include "../../lib/Templates/Vector.hpp"
#include <iostream>

class IPEntity {
public:
    virtual Vector2<int> getPosition() = 0;
    virtual std::string getName() = 0;
    virtual std::string getColor() = 0;
    virtual ~IPEntity() = default;
};

#endif //TEK2_IPENTITY_HPP
