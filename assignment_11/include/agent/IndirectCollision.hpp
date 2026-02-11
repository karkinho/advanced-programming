#ifndef INDIRECTCOLLISON_HPP
#define INDIRECTCOLLISON_HPP

#include "agent/ActionDecorator.hpp"
#include "algorithm/DStar.hpp"

class Agent;

class IndirectCollision : ActionDecorator {
protected:
    IndirectCollision * indirectCollision = nullptr;
    DStar * dStar = nullptr;
public:
    IndirectCollision( ActionDecorator * actionDecorator );
    ~IndirectCollision();
    using ActionDecorator::AddEnd;
    void Execute( Agent * agent ) override ;
};










#endif