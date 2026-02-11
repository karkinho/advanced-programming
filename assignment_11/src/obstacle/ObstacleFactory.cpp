#include "obstacle/ObstacleFactory.hpp"

ObstacleFactory::ObstacleFactory() {

}

ObstacleFactory::~ObstacleFactory() {
    
}

ObstacleFactory * ObstacleFactory::GetObstacleFactory() {
    if( obstacleFactory == nullptr ) {
        obstacleFactory = new ObstacleFactory();
    }
    return obstacleFactory;
}

Obstacle * ObstacleFactory::Create( OBSTACLE_TYPE obstacleType , Size_t2 position ) {
    switch (obstacleType)
    {
    case WALL:
        return ( Obstacle * )new Wall( position , INT_MAX );
        break;
    case MUD:
        return ( Obstacle * )new Mud( position , 3 );
        break;
    
    default:
        return nullptr;
        break;
    }
}