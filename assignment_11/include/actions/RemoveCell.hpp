#ifndef REMOVECELL_HPP
#define REMOVECELL_HPP

#include "actions/Command.hpp"
#include "Settings.hpp"
#include "grid/Cell.hpp"
#include "actions/RecalculatePaths.hpp"

class RemoveCell : Command
{
private:
    Cell * cell;
    RecalculatePaths * recalculatePaths;
public:
    RemoveCell();
    ~RemoveCell();
    void Execute() override;
};

#endif
