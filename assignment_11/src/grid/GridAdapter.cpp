#include "grid/GridAdapter.hpp"
#include "grid/Grid.hpp"


GridAdapter::GridAdapter( size_t rows , size_t columns , Vector4 windowSize ) {
    this->columns = columns;
    this->rows = rows;
    this->windowsSize = windowSize;
}

GridAdapter::~GridAdapter() {

}

Vector2 GridAdapter::GetCentroidOfCell( [[maybe_unused]] Size_t2 position ) {
    return Vector2{ 0 , 0 };
}

float GridAdapter::GetRadiusOfCell() {
    return 0;
}

std::vector< Size_t2 > GridAdapter::WhoIsMyNeighburs( [[maybe_unused]] Size_t2 position ) {
    return std::vector< Size_t2 >(0);
}

void GridAdapter::DrawGrid() {

}

Cell * GridAdapter::RemoveCell( [[maybe_unused]] Size_t2 position ) {
    return Grid::GetGrid()->Remove( position );
}

Size_t2 GridAdapter::GetGridPosition( [[maybe_unused]] Vector2 position ) {
    return Size_t2{ 0 , 0 };
}

void GridAdapter::FillCell( [[maybe_unused]] Color color , [[maybe_unused]] Size_t2 position ) {

}

void GridAdapter::RecalculatePaths( ) {
    Grid::GetGrid()->RecalculateAgents();
}

void GridAdapter::AddAgent( Size_t2 start ) {
    Grid::GetGrid()->AddAgent( start );
}

void GridAdapter::AddObstacle( Size_t2 position , OBSTACLE_TYPE type ) {
    Grid::GetGrid()->AddObstacle( type , position );
}

void GridAdapter::SetAgentEnd( Size_t2 end ) {
    Grid::GetGrid()->SetAgentEnd( end );
}

bool GridAdapter::GetEndAgentState() {
    return Grid::GetGrid()->GetEndAgentState();
}

bool GridAdapter::IsValidMousePosition( [[maybe_unused]] Vector2 position ) {
    return false;
}

void GridAdapter::MoveAgents() {
    return Grid::GetGrid()->MoveAgents();
}
void GridAdapter::ResetAgents() {
    Grid::GetGrid()->ResetAgents();
}

std::deque < Cell * > GridAdapter::GetCell( Size_t2 position ) {
    return Grid::GetGrid()->GetCell( position );
}

size_t GridAdapter::GetRows() {
    return this->rows;
}

size_t GridAdapter::GetCollums() {
    return this->columns;
}

std::pair< std::vector< Size_t2 > , std::vector< Size_t2 > > GridAdapter::GetChanges() {
    return Grid::GetGrid()->GetChanges(); 
}