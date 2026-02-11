#ifndef ACTIONDECORATOR_HPP
#define ACTIONDECORATOR_HPP

#include "agent/Agent.hpp"

class Agent;

class ActionDecorator {
protected:
    ActionDecorator * actionDecorator = nullptr;
public:
    ActionDecorator( ActionDecorator * actionDecorator );
    virtual ~ActionDecorator();
    void AddEnd( ActionDecorator * actionDecorator );
    virtual void Execute( Agent * agent );
};










#endif