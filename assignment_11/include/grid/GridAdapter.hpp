#ifndef GRIDADPTER_HPP
#define GRIDADPTER_HPP

#include "raylib.h"
#include "Settings.hpp"
#include "Cell.hpp"
#include <vector>
#include <deque>


class GridAdapter
{
protected:
    size_t rows, columns;
    Vector4 windowsSize;
    
public:
    GridAdapter( size_t rows , size_t columns , Vector4 windowSize );
    size_t GetRows();
    size_t GetCollums();
    virtual ~GridAdapter();
    virtual Vector2 GetCentroidOfCell( Size_t2 position );
    virtual float GetRadiusOfCell();
    virtual std::vector< Size_t2 > WhoIsMyNeighburs( Size_t2 position );
    virtual void DrawGrid();
    virtual Cell * RemoveCell( Size_t2 position );
    virtual Size_t2 GetGridPosition( Vector2 position );
    virtual void RecalculatePaths();
    virtual void FillCell( Color color , Size_t2 position );
    virtual void AddAgent( Size_t2 start );
    virtual void SetAgentEnd( Size_t2 end );
    virtual void AddObstacle( Size_t2 position , OBSTACLE_TYPE type );
    virtual bool GetEndAgentState();
    virtual bool IsValidMousePosition( Vector2 position );
    virtual void MoveAgents();
    virtual void ResetAgents();
    virtual std::pair< std::vector< Size_t2 > , std::vector< Size_t2 > > GetChanges();
    virtual std::deque< Cell * > GetCell( Size_t2 position );
};

#endif