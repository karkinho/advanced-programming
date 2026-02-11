#ifndef ADDOBSTACLE_HPP
#define ADDOBSTACLE_HPP

#include "actions/AddCommand.hpp"
#include "Settings.hpp"

class AddObstacle : AddCommand
{
protected:
    OBSTACLE_TYPE obstacleType;
    Size_t2 position;
public:
    AddObstacle( OBSTACLE_TYPE obstacleType );
    ~AddObstacle();
    void Execute() override;
};

#endif