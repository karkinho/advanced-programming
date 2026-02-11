#include "initialization/InitGrid.hpp"
#include "grid/Grid.hpp"

InitGrid::InitGrid() : BaseHandler() {
}

InitGrid::~InitGrid() {

}

InicializationVariables InitGrid::Execute( InicializationVariables variables ) {
    Grid::Initialize( variables.rows , variables.columns );

    return BaseHandler::Execute( variables );
}

