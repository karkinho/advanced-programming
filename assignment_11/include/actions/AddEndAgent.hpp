#ifndef ADDENDAGENT_HPP
#define ADDENDAGENT_HPP

#include "actions/AddCommand.hpp"
#include "Settings.hpp"

class AddEndAgent : AddCommand
{
protected:
    Size_t2 end;
public:
    AddEndAgent();
    virtual ~AddEndAgent();
    virtual void Execute();
};

#endif