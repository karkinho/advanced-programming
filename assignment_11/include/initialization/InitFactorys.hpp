#ifndef INITFACTORYS_HPP
#define INITFACTORYS_HPP

#include "initialization/BaseHandler.hpp"

class InitFactorys : BaseHandler
{
private:
    
public:
    InitFactorys();
    ~InitFactorys();
    using BaseHandler::SetNext;
    using BaseHandler::AddEnd;
    InicializationVariables Execute( InicializationVariables variables ) override;
};

#endif