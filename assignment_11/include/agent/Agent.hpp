#ifndef AGENT_HPP
#define AGENT_HPP

#include "raylib.hpp"
#include "grid/Cell.hpp"
#include "Settings.hpp"
#include <vector>
#include "agent/ActionDecorator.hpp"
#include "grid/GridAdapter.hpp"

class ActionDecorator;

class Agent : Cell
{
protected:
    Size_t2 start , end;
    std::vector< std::vector< size_t > > pathDiscrete;
    std::vector< Vector2 > pathContinuous;
    ActionDecorator * actionDecorator;
    GridAdapter * gridAdapter;
    bool endState;
    Color color;
    float radius;
public:
    size_t tSpline;
    Agent( Size_t2 position , Size_t2 start , float velocity , float radius , Color color );
    ~Agent();
    void SetEndPoint( Size_t2 end );
    void CalculatePath();
    void Draw() override;
    void DrawAgent();
    bool GetEndState();
    using Cell::GetPosition;
    Size_t2 GetEnd();
    Size_t2 GetStart();
    std::vector< std::vector< size_t > > GetPathDiscrete();
    std::vector< Vector2 > GetPathContinuous();
    void Tick() override;
    void MoveAgentInGrid( Size_t2 position );
    using Cell::GetDynamic;
    using Cell::GetCollisor;
    bool ReachedDestination();
    void Reset();
    float GetRadius();
    std::vector< Size_t2 > LowestNeighbur( Size_t2 position );
    void SetPath( std::vector< std::vector< size_t > > discretePath );
};

#endif