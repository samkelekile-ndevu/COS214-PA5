#ifndef SENSOR_H
#define SENSOR_H
#include"SmartDevice.h"
#include<vector>
#include<algorithm>
class Sensor
{
    private:
    vector<SmartDevice*> devices;

    public: 
    void addDevice(SmartDevice* device) {
        devices.push_back(device);
    }

    void removeDevice(SmartDevice* device) {
        devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
    }

    // Trigger the notification when a sensor detects something
    void notifyDevices(const std::string& event) {
        for (SmartDevice* device : devices) {
            device->update(event);  // Notify each device about the event
        }
    }

};
#endif