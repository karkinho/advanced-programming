#include "actions/AddEndAgent.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"
#include "raylib.hpp"
#include "actions/RecalculatePaths.hpp"
#include "actions/RemoveCell.hpp"

AddEndAgent::AddEndAgent() {

}

AddEndAgent::~AddEndAgent() {

}

void AddEndAgent::Execute() {
    recalculatePaths = new RecalculatePaths();
    removeCell = new RemoveCell();
    removeCell->Execute(); 
    GridAdapter * grid = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter() ;
    end = grid->GetGridPosition( GetMousePosition() );
    grid->SetAgentEnd( end );
    recalculatePaths->Execute();
    delete grid;
}
