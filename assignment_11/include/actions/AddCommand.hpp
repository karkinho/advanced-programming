#ifndef ADDCOMMAND_HPP
#define ADDCOMMAND_HPP

#include "actions/Command.hpp"
#include "actions/RemoveCell.hpp"
#include "actions/RecalculatePaths.hpp"


class AddCommand : Command
{
protected:
    RemoveCell * removeCell;
    RecalculatePaths * recalculatePaths;
public:
    AddCommand();
    virtual ~AddCommand();
    virtual void Execute();
};

#endif