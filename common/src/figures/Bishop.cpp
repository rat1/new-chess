#include "figures/Bishop.h"

Chess::Bishop::Bishop(const GameObject::ObjectId& id, Chess::Color color, uint32_t row, uint32_t column)
    : Figure(id, "B", row, column, color)
{
}
