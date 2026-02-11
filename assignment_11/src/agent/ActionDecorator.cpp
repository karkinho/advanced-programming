#include "agent/ActionDecorator.hpp"

ActionDecorator::ActionDecorator( ActionDecorator * actionDecorator ) {
    this->actionDecorator = actionDecorator;
}

void ActionDecorator::AddEnd( ActionDecorator * actionDecorator ) {
    if( actionDecorator == nullptr ) {
        this->actionDecorator = actionDecorator;
    } else {
        actionDecorator->AddEnd( actionDecorator );
    }
}

ActionDecorator::~ActionDecorator() {
    delete actionDecorator;
}

void ActionDecorator::Execute( Agent * agent ) {
    if( actionDecorator != nullptr ) {
        actionDecorator->Execute( agent ); 
    }
}

