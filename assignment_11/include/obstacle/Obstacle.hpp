#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "grid/Cell.hpp"
#include "raylib.hpp"
#include <vector>
#include "limits.h"

class Obstacle : Cell
{
protected:
    size_t cost;
    Color color;
public:
    Obstacle( Size_t2 position , size_t cost );
    virtual ~Obstacle();
    size_t GetCost();
    void Draw() override;
    using Cell::GetPosition;
};

#endif