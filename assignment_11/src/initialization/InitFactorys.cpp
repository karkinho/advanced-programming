#include "initialization/InitFactorys.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "obstacle/ObstacleFactory.hpp"
#include "agent/CollisionFactory.hpp"
#include "Settings.hpp"

InitFactorys::InitFactorys() : BaseHandler() {
}

InitFactorys::~InitFactorys() {

}

InicializationVariables InitFactorys::Execute( InicializationVariables variables ) {
    GridAdapterFactory::Initialize( variables.typeGrid , variables.rows , variables.columns , variables.windowSize );
    ObstacleFactory::GetObstacleFactory();
    CollisonFactory::CreateFactory( INDIRECT_COMMUNICATION );
    return BaseHandler::Execute( variables );
}

