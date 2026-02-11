#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command
{
private:

public:
    Command();
    virtual ~Command();
    virtual void Execute();
};

#endif