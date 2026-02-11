#include "actions/RecalculatePaths.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"

RecalculatePaths::RecalculatePaths() {

}

RecalculatePaths::~RecalculatePaths() {

}

void RecalculatePaths::Execute() {
    GridAdapter * grid = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter() ;
    grid->RecalculatePaths();
    delete grid;
}