#include "actions/Invoker.hpp"
#include "raylib.hpp"
#include "actions/RemoveCell.hpp"
#include "actions/AddAgent.hpp"
#include "actions/AddEndAgent.hpp"
#include "actions/AddObstacle.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "actions/MoveAgents.hpp"
#include "input/InputPublisher.hpp"
#include "actions/ResetAgents.hpp"

Invoker::Invoker() {
    gridAdapter = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter();
}

Invoker::~Invoker() {
    for ( size_t i = 0 ; i < actionList.size() ; i++ ) {
        delete actionList[i];
    }
    actionList.clear();
    delete gridAdapter;
}

Invoker * Invoker::GetInvoker() {
    if( invoker == nullptr ) {
        invoker = new Invoker();
    }
    return invoker;
}
void Invoker::Notification() {
    Command * command = nullptr;
    switch (InputPublisher::GetInputPublisher()->GetInput())
    {
        case LEFT_CLICK:
            if( gridAdapter->GetEndAgentState() ) {
                command = ( Command * ) new AddAgent();
            } else {
                command = ( Command * ) new AddEndAgent();
            }
            break;
        case RIGHT_CLICK:
            command = ( Command * ) new RemoveCell();
            break;
        case ONE:
            command = ( Command * ) new AddObstacle( MUD );
            break;
        case TWO:
            command = ( Command * ) new AddObstacle( WALL );
            break;
        case THREE:
            command = ( Command * ) new MoveAgents();
            break;
        case FOUR:
            command = ( Command * ) new ResetAgents();
            break;
        default:
            break;
    }
    if( command != nullptr ) {
        command->Execute();
        actionList.push_back( command );
    }
}