#include "initialization/BaseHandler.hpp"

BaseHandler::BaseHandler() {
    this->next = nullptr;
}

BaseHandler::~BaseHandler() {
    if( next != nullptr ) {
       delete next;
    }
}
void BaseHandler::SetNext( BaseHandler * baseHandler ) {
    this->next = baseHandler;
}

void BaseHandler::AddEnd( BaseHandler * baseHandler ) {
    if( next != nullptr ) {
        next->AddEnd( baseHandler );
    } else {
        SetNext( baseHandler );
    }
}

InicializationVariables BaseHandler::Execute( InicializationVariables variables ) {
    if( next != nullptr ) {
        return next->Execute( variables );
    }
    return variables;
}

