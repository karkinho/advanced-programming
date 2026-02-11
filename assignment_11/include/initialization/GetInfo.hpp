#ifndef GETINFO_HPP
#define GETINFO_HPP

#include "initialization/BaseHandler.hpp"

class GetInfo : BaseHandler
{
private:
    
public:
    GetInfo();
    ~GetInfo();
    using BaseHandler::SetNext;
    using BaseHandler::AddEnd;
    InicializationVariables Execute( InicializationVariables variables ) override;
};

#endif