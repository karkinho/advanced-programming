#ifndef INITGRID_HPP
#define INITGRID_HPP

#include "initialization/BaseHandler.hpp"

class InitGrid : BaseHandler
{
private:
    
public:
    InitGrid();
    ~InitGrid();
    using BaseHandler::SetNext;
    using BaseHandler::AddEnd;
    InicializationVariables Execute( InicializationVariables variables ) override;
};

#endif