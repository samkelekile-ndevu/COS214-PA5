#ifndef COMMAND_H
#define COMMAND_H
//COMMAND AND MACRO-COMMAND
class Command
{
    public:
    virtual void execute() = 0;
    virtual ~Command() = default;

};
#endif