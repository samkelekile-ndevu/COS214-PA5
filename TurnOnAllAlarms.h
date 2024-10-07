/**
 * @class TurnOnAllAlarms
 * @brief Command class to turn on all alarm devices in the smart home automation system.
 *
 * This class implements the Command interface to provide the functionality 
 * for activating all alarm devices within the system. It iterates through 
 * the list of devices and invokes the turn on action on each alarm device.
 *
 * @section methods Methods
 * - execute(): Executes the command to turn on all alarm devices.
 */

#ifndef TURNONALLALARMS_H
#define TURNONALLALARMS_H
#include"Command.h"
#include"SmartDevice.h"
#include<vector>
#include<algorithm>
class TurnOnAllAlarms : public Command
{
    private: vector<SmartDevice*>& devices;
    public:
    TurnOnAllAlarms(std::vector<SmartDevice*>& devices) : devices(devices) {}
    void execute() override {
        for (auto& device : devices) {
            if (device->getDeviceType() == "Alarm") {
                device->performAction("TurnOn");  // turn on all alarms
            }
        }
    }

};
#endif
