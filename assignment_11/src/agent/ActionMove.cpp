#include "agent/ActionMove.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"
#include "common/Clock.hpp"

ActionMove::ActionMove( ActionDecorator * actionDecorator ) : ActionDecorator( actionDecorator ) {

}

ActionMove::~ActionMove() {

}

void ActionMove::Execute( Agent * agent ) {
    if( agent->ReachedDestination() ) {
        return;
    }
    GridAdapter * adapter = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter();
    double deltaTime = Clock::GetClock()->GetTick();
    float velocity = agent->GetDynamic()->GetVelocity() * deltaTime;
    Vector2 dirVec = agent->GetDynamic()->GetDirectionVector( agent );
    dirVec.x *= velocity;
    dirVec.y *= velocity;
    Vector2 position = agent->GetDynamic()->GetDynamicPosition();
    position.x += dirVec.x;
    position.y += dirVec.y;
    agent->GetDynamic()->SetDynamicPosition( position );
    agent->MoveAgentInGrid( adapter->GetGridPosition( agent->GetDynamic()->GetDynamicPosition() ) );
    delete adapter;
    ActionDecorator::Execute( agent );
}