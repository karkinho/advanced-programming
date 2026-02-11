#include "agent/CollisionFactory.hpp"
#include "agent/IndirectCollision.hpp"

CollisonFactory::CollisonFactory( COLLISION_METHOD collision ) {
    this->collision = collision;
}


CollisonFactory::~CollisonFactory() {
    this->collisonFactory = nullptr;    
}

void CollisonFactory::CreateFactory( COLLISION_METHOD collision ) {
    if( CollisonFactory::collisonFactory != nullptr ) {
        return;
    }
    CollisonFactory::collisonFactory = new CollisonFactory( collision );    
}

CollisonFactory * CollisonFactory::GetCollisonFactory() {
    return collisonFactory;
}

COLLISION_METHOD CollisonFactory::GetCollisionMethod() {
    return collision;
}

ActionDecorator * CollisonFactory::GetCollisionHandler( ActionDecorator * actionDecorator ) {
    switch (this->collision) {
    case INDIRECT_COMMUNICATION:
        return ( ActionDecorator * ) new IndirectCollision( actionDecorator );
        break;
    case DIRECT_COMMUNICATION:
        return nullptr;
        break;
    case NO_COMMUNICATION:
        return nullptr;
        break;
    default:
        return nullptr;
        break;
    }
}