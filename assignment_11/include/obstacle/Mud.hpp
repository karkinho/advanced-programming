#ifndef MUD_HPP
#define MUD_HPP


#include "grid/Cell.hpp"
#include "raylib.hpp"
#include <vector>
#include "obstacle/Obstacle.hpp"
#include "limits.h"

class Mud : Obstacle
{
protected:
public:
    Mud( IntVector2 position , size_t cost );
    ~Mud();
    using Obstacle::GetCost;
};

#endif