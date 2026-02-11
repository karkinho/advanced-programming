#include "agent/IndirectCollision.hpp"


IndirectCollision::IndirectCollision( ActionDecorator * actionDecorator ) : ActionDecorator( actionDecorator ) {
    
}

IndirectCollision::~IndirectCollision() {

}

void IndirectCollision::Execute( Agent * agent ) {
    if( !agent->GetEndState() ) {
        return;
    }
    if( this->dStar == nullptr ) {
        dStar = new DStar( agent->GetStart() , agent->GetEnd() );
        dStar->CalculateShortesPath();
    } else {
        dStar->Replan( agent );
    }
    agent->SetPath( dStar->GetDistances() );

    ActionDecorator::Execute( agent );
}



