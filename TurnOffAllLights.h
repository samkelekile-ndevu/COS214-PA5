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
