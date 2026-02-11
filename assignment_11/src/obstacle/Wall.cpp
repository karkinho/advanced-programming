#include "obstacle/Wall.hpp"

Wall::Wall( Size_t2 position , size_t cost ) : Obstacle( position , cost ) {
    this->color = GRAY;
}

Wall::~Wall() {
    
}