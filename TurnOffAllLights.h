/**
 * @class TurnOffAllLights
 * @brief Command class to turn off all light devices in the smart home automation system.
 *
 * This class implements the Command interface to provide the functionality 
 * for deactivating all light devices within the system. It iterates through 
 * the list of devices and invokes the toggle off action on each light device.
 *
 * @section methods Methods
 * - execute(): Executes the command to turn off all light devices.
 */

#ifndef TURNOFFALLLIGHTS_H
#define TURNOFFALLLIGHTS_H
#include"Command.h"
#include"SmartDevice.h"
#include<vector>
#include<algorithm>
class TurnOffAllLights : public Command
{
    private: vector<SmartDevice*>& devices;
    public:
    TurnOffAllLights(std::vector<SmartDevice*>& devices) : devices(devices) {}
    void execute() override {
        for (auto& device : devices) {
            if (device->getDeviceType() == "Light") {
                device->performAction("ToggleOff");  // switch lights off
            }
        }
    }

};
#endif
