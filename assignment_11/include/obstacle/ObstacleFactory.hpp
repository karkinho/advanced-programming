#ifndef OBSTACLEFACTORY_HPP
#define OBSTACLEFACTORY_HPP

#include "obstacle/Obstacle.hpp"
#include "obstacle/Wall.hpp"
#include "obstacle/Mud.hpp"

class ObstacleFactory
{
private:
    ObstacleFactory();
    inline static ObstacleFactory * obstacleFactory = nullptr;
public:
    ~ObstacleFactory();
    static ObstacleFactory * GetObstacleFactory();
    Obstacle * Create( OBSTACLE_TYPE obstacleType , Size_t2 position );
};














#endif