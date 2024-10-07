/**
 * @class Command
 * @brief Abstract base class for command objects in the smart home automation system.
 *
 * This class defines the interface for command execution, allowing different commands
 * to be implemented and executed in a uniform manner. It serves as a base class for 
 * specific command implementations, such as locking doors or turning off lights.
 *
 * @section methods Methods
 * - execute(): Executes the command.
 */

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
