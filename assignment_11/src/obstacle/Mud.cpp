#include "obstacle/Mud.hpp"

Mud::Mud( Size_t2 position , size_t cost ) : Obstacle( position , cost ) {
    this->color = BROWN;
}

Mud::~Mud() {
    
}