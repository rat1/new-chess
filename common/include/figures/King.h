#pragma once

#include "Figure.h"

namespace Chess {

class King : public Figure {
public:
    King(const GameObject::ObjectId& id,
         Color color,
         uint32_t row = 0,
         uint32_t column = 0);
};

}
