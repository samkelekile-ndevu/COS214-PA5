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
