#ifndef WALL_HPP
#define WALL_HPP


#include "grid/Cell.hpp"
#include "raylib.hpp"
#include <vector>
#include "obstacle/Obstacle.hpp"
#include "limits.h"

class Wall : Obstacle
{
protected:
public:
    Wall( IntVector2 position , size_t cost );
    ~Wall();
    using Obstacle::GetCost;
};

#endif