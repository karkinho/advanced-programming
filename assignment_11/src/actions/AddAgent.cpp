#include "actions/AddAgent.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"
#include "raylib.hpp"

AddAgent::AddAgent() {

}

AddAgent::~AddAgent() {

}

void AddAgent::Execute() {
    recalculatePaths = new RecalculatePaths();
    removeCell = new RemoveCell();
    removeCell->Execute(); 
    GridAdapter * grid = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter() ;
    start = grid->GetGridPosition( GetMousePosition() );
    grid->AddAgent( start );
    recalculatePaths->Execute();
    delete grid;
}
