#ifndef MOVEAGENTS_HPP
#define MOVEAGENTS_HPP

#include "actions/Command.hpp"
#include <fstream>
#include <iostream>
#include <string>

class MoveAgents : Command
{
private:
public:
    MoveAgents();
    virtual ~MoveAgents();
    virtual void Execute();
};

#endif