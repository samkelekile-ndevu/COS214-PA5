/**
 * @class MacroRoutine
 * @brief Represents a composite command that can execute a sequence of commands.
 *
 * The MacroRoutine class inherits from Command and allows for the 
 * management of multiple Command objects. It can add or remove commands 
 * from its list and execute them in sequence, enabling complex actions 
 * to be performed as a single command.
 *
 * @section methods Methods
 * - addProcedure(Command* command): Adds a command to the macro routine.
 * - removeProcedure(Command* command): Removes a command from the macro routine.
 * - execute(): Executes all commands in the order they were added.
 */

#ifndef MACROROUTINE_H
#define MACROROUTINE_H
#include"Command.h"
#include<vector>
#include<algorithm>
using namespace std;
class MacroRoutine : public Command
{
    private:
    vector<Command*> procedures;
    public:
     void addProcedure(Command* command) {
        procedures.push_back(command);
    }

    void removeProcedure(Command* command) {
        procedures.erase(std::remove(procedures.begin(), procedures.end(), command), procedures.end());
    }

    void execute() override {
        for (auto& command : procedures) {
            command->execute();  // Execute each command in the sequence
        }
    }


};
#endif
