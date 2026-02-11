#ifndef GRID_HPP
#define GRID_HPP

#include "raylib.hpp"
#include "Settings.hpp"
#include "grid/Cell.hpp"
/* #include "agent/Agent.hpp" */
#include <vector>
#include <tuple>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include "grid/GridAdapter.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "obstacle/ObstacleFactory.hpp"
#include <deque>

class Agent;

class Grid
{
protected:
    std::vector< std::vector< std::deque < Cell * > > > grid;
    std::vector< Agent * > agents;
    std::vector< Obstacle * > obstacles; 
    size_t rows = 0, columns = 0;
    inline static Grid * gridptr = nullptr;
    Grid( size_t rows, size_t columns );
    GridAdapter * gridAdapter;
    std::vector< Size_t2 > changedThisTick , changedLastTick;
public:
    std::pair< std::vector< Size_t2 > , std::vector< Size_t2 > > GetChanges();
    static Grid * GetGrid();
    static void Initialize( size_t rows , size_t columns );
    ~Grid();
    void Draw();
    std::vector< std::vector < std::deque< Cell * > > > GetBoard();
    std::vector< Obstacle * > GetObstacles();
    void AddObstacle( OBSTACLE_TYPE type , Size_t2 position );
    void AddAgent( Size_t2 position );
    Cell * Remove( Size_t2 position );
    void RecalculateAgents();
    void SetAgentEnd( Size_t2 position );
    bool GetEndAgentState(); 
    void MoveAgent( Size_t2 from , Size_t2 to , Agent * agent );
    void MoveAgents();
    void DrawAgents();
    void ResetAgents();
    std::deque< Cell * > GetCell( Size_t2 position );
};




#endif