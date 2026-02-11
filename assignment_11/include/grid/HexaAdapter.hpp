#ifndef HEXAADPTER_HPP
#define HEXAADPTER_HPP

#include "raylib.h"
#include "Settings.hpp"
#include "Cell.hpp"
#include <vector>
#include "grid/GridAdapter.hpp"
#include <cmath>
#include <iostream>

class HexaAdapter : GridAdapter
{
private:
    float width, height, offsetWidth, offsetHeight, centerOffset;
    std::vector< std::vector < Vector2 > > centroids;
public:
    HexaAdapter(  size_t rows , size_t columns , Vector4 windowSize  );
    ~HexaAdapter();
    Vector2 GetCentroidOfCell( Size_t2 position ) override;
    float GetRadiusOfCell() override;
    std::vector< Size_t2 > WhoIsMyNeighburs( Size_t2 position ) override;
    void DrawGrid() override;
    using GridAdapter::RemoveCell;
    using GridAdapter::RecalculatePaths;
    using GridAdapter::AddAgent;
    using GridAdapter::SetAgentEnd;
    using GridAdapter::AddObstacle;
    using GridAdapter::GetEndAgentState;
    using GridAdapter::MoveAgents;
    using GridAdapter::ResetAgents;
    using GridAdapter::GetCell;
    using GridAdapter::GetRows;
    using GridAdapter::GetCollums;
    using GridAdapter::GetChanges;
    Size_t2 GetGridPosition( Vector2 position ) override;
    void FillCell( Color color , Size_t2 position ) override;
    bool IsValidMousePosition( Vector2 position ) override;
};

#endif