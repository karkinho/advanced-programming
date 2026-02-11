#include "actions/MoveAgents.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "common/Clock.hpp"

MoveAgents::MoveAgents() {
}

MoveAgents::~MoveAgents() {

}

void MoveAgents::Execute() {
    GridAdapter * grid = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter() ;
    grid->MoveAgents();
    delete grid;
}