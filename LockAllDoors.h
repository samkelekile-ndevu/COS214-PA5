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