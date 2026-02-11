#include "common/Collisor.hpp"
#include <cstddef>

Collisor::Collisor( size_t cost , bool isCellFill , float radius ) {
    this->cost = cost;
    this->isCellFill = isCellFill;
    this->radius = radius;
    this->warningRadius = 1.5 * radius;
}

Collisor::~Collisor() {

}

size_t Collisor::GetCost() {
    return cost;
}

float Collisor::GetRadius() {
    return radius;
}

bool Collisor::IsCellFill() {
    return isCellFill;
}

float Collisor::GetWarningRadius() {
    return warningRadius;
}