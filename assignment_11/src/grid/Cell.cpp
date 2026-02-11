#include "grid/Cell.hpp"

Cell::Cell( Size_t2 position , Dynamic * dynamic , Collisor * collisor ) {
    this->position = position;
    this->collisor = collisor;
    this->dynamic = dynamic;
}

Cell::~Cell() {

}

void Cell::Draw() {
    
}

Size_t2 Cell::GetPosition() {
    return position;
}

Collisor * Cell::GetCollisor() {
    return collisor;
}

Dynamic * Cell::GetDynamic() {
    return dynamic;
}

void Cell::Tick() {

}