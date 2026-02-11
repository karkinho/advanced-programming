#include "initialization/InitUi.hpp"
#include "grid/Grid.hpp"
#include "actions/Invoker.hpp"
#include "input/InputPublisher.hpp"
#include "common/Clock.hpp"

InitUi::InitUi() : BaseHandler() {
}

InitUi::~InitUi() {

}

InicializationVariables InitUi::Execute( InicializationVariables variables ) {
    InitWindow( variables.windowSize.z , variables.windowSize.w , " >w< :3 :D UwU " );
    InputPublisher::GetInputPublisher()->AddSubscriber( ( Subscriber * ) Invoker::GetInvoker() );
    Clock::GetClock();

    return BaseHandler::Execute( variables );
}

