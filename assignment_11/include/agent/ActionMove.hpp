#ifndef ACTIONMOVE_HPP
#define ACTIONMOVE_HPP

#include "agent/Agent.hpp"
#include "agent/ActionDecorator.hpp"

class ActionMove : ActionDecorator {
private:

public:
    ActionMove( ActionDecorator * actionDecorator );
    ~ActionMove();
    void Execute( Agent * agent ) override;
    using ActionDecorator::AddEnd;
};










#endif