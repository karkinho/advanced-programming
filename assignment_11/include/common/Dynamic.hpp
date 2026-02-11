#ifndef DYNAMIC_HPP
#define DYNAMIC_HPP

#include "raylib.hpp"

class Agent;

class Dynamic
{
private:
    Vector2 dynamicPosition;
    float velocity;
    Vector2 localObjective = { - 1 ,  - 1 }, direction;
    double distance;
public:
    Dynamic( Vector2 dynamicPositon , float velocity );
    ~Dynamic();
    float GetVelocity();
    void SetDynamicPosition( Vector2 position );
    Vector2 GetDynamicPosition();
    Vector2 GetDirectionVector( Agent * agent );
    void SetDirection( Vector2 dir );
    void Reset();
};

#endif
