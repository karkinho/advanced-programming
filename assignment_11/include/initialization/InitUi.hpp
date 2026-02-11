#ifndef INITUI_HPP
#define INITUI_HPP

#include "initialization/BaseHandler.hpp"

class InitUi : BaseHandler
{
private:
    
public:
    InitUi();
    ~InitUi();
    using BaseHandler::SetNext;
    using BaseHandler::AddEnd;
    InicializationVariables Execute( InicializationVariables variables ) override;
};

#endif