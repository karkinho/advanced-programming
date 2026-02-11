#include "actions/RemoveCell.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"
#include "raylib.hpp"

RemoveCell::RemoveCell() {

}

RemoveCell::~RemoveCell() {
    delete cell;
}

void RemoveCell::Execute() {
    recalculatePaths = new RecalculatePaths();
    GridAdapter * grid = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter() ;
    cell = grid->RemoveCell( grid->GetGridPosition( GetMousePosition() ) );
    recalculatePaths->Execute();
    delete grid;
}