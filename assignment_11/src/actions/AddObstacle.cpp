#include "actions/AddObstacle.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"
#include "raylib.hpp"

AddObstacle::AddObstacle( OBSTACLE_TYPE obstacleType ) {
    this->obstacleType = obstacleType;
}

AddObstacle::~AddObstacle() {

}

void AddObstacle::Execute() {
    recalculatePaths = new RecalculatePaths();
    removeCell = new RemoveCell();
    removeCell->Execute(); 
    GridAdapter * grid = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter() ;
    grid->AddObstacle( grid->GetGridPosition( GetMousePosition() ) , obstacleType );
    recalculatePaths->Execute();
    delete grid;
}