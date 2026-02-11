#include "obstacle/Obstacle.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"
#include "common/Collisor.hpp"

Obstacle::Obstacle( Size_t2 position , size_t cost ) : Cell( position , nullptr , nullptr ) {
    this->color = BLACK;
    Collisor * collisor = new Collisor( cost , true , 0 );
    this->collisor = collisor;
}

Obstacle::~Obstacle() {

}

size_t Obstacle::GetCost() {
    return collisor->GetCost();
}

void Obstacle::Draw() {
    GridAdapterFactory * gridAdapterFactory = GridAdapterFactory::GetGridAdapterFactory();
    GridAdapter * gridAdapter = gridAdapterFactory->GetAdapter();
    gridAdapter->FillCell( color , position );
    delete gridAdapter;
}