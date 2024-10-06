//COMPOSTIE OF COMMANDS SO YOU CAN ALSO ADD COMMANDS WHEN NEEDED
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