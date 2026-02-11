#ifndef RECALCULATEPATHS_HPP
#define RECALCULATEPATHS_HPP

#include "actions/Command.hpp"

class RecalculatePaths : Command
{
protected:
public:
    RecalculatePaths();
    ~RecalculatePaths();
    void Execute() override;
};

#endif