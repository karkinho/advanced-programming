#ifndef COLLISIONFACTORY_HPP
#define COLLISIONFACTORY_HPP

#include "Settings.hpp"
#include "agent/ActionDecorator.hpp"


class CollisonFactory
{
private:
    CollisonFactory( COLLISION_METHOD collision );
    inline static CollisonFactory * collisonFactory = nullptr;
    COLLISION_METHOD collision;
public:
    ~CollisonFactory();
    static void CreateFactory( COLLISION_METHOD collision );
    static CollisonFactory * GetCollisonFactory();
    ActionDecorator * GetCollisionHandler( ActionDecorator * actionDecorator );
    COLLISION_METHOD GetCollisionMethod();
};


#endif