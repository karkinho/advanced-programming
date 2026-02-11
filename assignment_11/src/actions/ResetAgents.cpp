#include "actions/ResetAgents.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"

ResetAgents::ResetAgents() {

}

ResetAgents::~ResetAgents() {

}

void ResetAgents::Execute() {
    GridAdapter * grid = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter() ;
    grid->ResetAgents();
    delete grid;
}