#ifndef RESETAGENTS_HPP
#define RESETAGENTS_HPP

#include "actions/Command.hpp"

class ResetAgents : Command
{
private:

public:
    ResetAgents();
    virtual ~ResetAgents();
    virtual void Execute();
};

#endif