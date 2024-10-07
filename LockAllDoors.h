/**
 * @class LockAllDoors
 * @brief Command class to lock all door lock devices in the smart home automation system.
 *
 * This class implements the Command interface to provide the functionality 
 * for locking all door lock devices within the system. It iterates through 
 * the list of devices and invokes the lock action on each door lock device.
 *
 * @section methods Methods
 * - execute(): Executes the command to lock all door lock devices.
 */

#ifndef LOCKALLDOORS_H
#define LOCKALLDOORS_H
#include"Command.h"
#include"SmartDevice.h"
#include<vector>
#include<algorithm>
class LockAllDoors : public Command
{
    private:
    vector<SmartDevice*> devices;
    public:
     LockAllDoors(std::vector<SmartDevice*>& devices) : devices(devices) {}

    void execute() override {
        for (auto& device : devices) {
            if (device->getDeviceType() == "DoorLock") {
                device->performAction("Lock");  // lock doors
            }
        }
    }



};
#endif
