#ifndef ADDAGENT_HPP
#define ADDAGENT_HPP

#include "actions/AddCommand.hpp"


class AddAgent : AddCommand
{
protected:
    Size_t2 start;
public:
    AddAgent();
    virtual ~AddAgent();
    virtual void Execute();
};

#endif