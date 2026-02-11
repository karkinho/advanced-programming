#include "common/Dynamic.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "grid/GridAdapter.hpp"
#include "agent/Agent.hpp"
#include "Settings.hpp"
#include "common/Clock.hpp"

Dynamic::Dynamic( Vector2 dynamicPosition , float velocity ) {
    this->dynamicPosition = dynamicPosition;
    this->velocity = velocity;
    this->distance = -1;
}

Dynamic::~Dynamic() {

}

Vector2 Dynamic::GetDynamicPosition() {
    return dynamicPosition;
}

float Dynamic::GetVelocity() {
    return velocity;
}

Vector2 Dynamic::GetDirectionVector( Agent * agent ) {
    /* auto compare = [] ( Size_t2 a , Size_t2 b ) {
        return a.x == b.x && a.y == b.y;
    }; */
    GridAdapter * adapter = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter();
    Size_t2 nextCell = agent->LowestNeighbur( agent->GetPosition() );
    Vector2 dir;

    if( distance > 0 ) {
        distance -= velocity * Clock::GetClock()->GetTick();
        if( distance <= 0 ) {
            localObjective = adapter->GetCentroidOfCell( nextCell );
        }
        delete adapter;
        return direction;
    }

    if( ( localObjective.x == -1 && localObjective.y == -1 ) ) {
        localObjective = adapter->GetCentroidOfCell( nextCell );
    }
    if( compareFloat( localObjective , agent->GetDynamic()->GetDynamicPosition() , 0.004 ) ) {
        localObjective = adapter->GetCentroidOfCell( nextCell );
    }
    
    dir = normalize( dirVector( agent->GetDynamic()->GetDynamicPosition() , localObjective ) );
    delete adapter;
    return dir;
}

void Dynamic::SetDynamicPosition( Vector2 position ) {
    this->dynamicPosition = position;
}

void Dynamic::SetDirection( Vector2 dir ) {
    GridAdapter * adapter = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter();
    if( distance > adapter->GetRadiusOfCell() * 1.25 * 0.95) {
        delete adapter;
        return;
    }
    this->direction = dir;
    this->distance = adapter->GetRadiusOfCell() * 1.25;
    delete adapter;
}

void Dynamic::Reset() {
    this->distance = -1;
    this->localObjective = Vector2{ -1 , -1 };
}